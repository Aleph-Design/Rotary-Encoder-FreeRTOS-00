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

  Serial.println("\n--- Encoder Station FreeRTOS 00 ---\n");

  pinMode(pin_CLK, INPUT_PULLUP);
  pinMode(pin_DT, INPUT_PULLUP);
  pinMode(pin_SW, INPUT_PULLUP);

  Serial.printf("max steps: %d\n", MAX_INDEX);

  // Create the mutual exclusive semaphore
  //
  sMutex = xSemaphoreCreateMutex();

  createAllTasks();
}

void loop() 
{}
