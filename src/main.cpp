#include <tasksConfig.h>
#include <createAllTasks.h>

// Initialize the semaphore defined in rotaryEncoderTask.h to protect the
// struct Coder.
//
SemaphoreHandle_t sMutex = NULL;

void setup() 
{
  Serial.begin(115200);
  vTaskDelay(1000 / portTICK_PERIOD_MS);	// Stabilize serial

  Serial.println("\n--- Rotary Encoder Count Matrix ---\n");

  pinMode(pin_CLK, INPUT_PULLUP);
  pinMode(pin_DT, INPUT_PULLUP);
  pinMode(pin_SW, INPUT_PULLUP);

  // Create the mutual exclusive semaphore
  //
  sMutex = xSemaphoreCreateMutex();

  createAllTasks();
}

void loop() 
{
  if (sMutex != NULL)
  {
    if (xSemaphoreTake(sMutex, (TickType_t) 10) == pdTRUE)
    {
      Serial.printf("\nCoder main index: %d pressed:%d\n",
                                coder.index, coder.select);
      xSemaphoreGive(sMutex);
    }
  }
}
