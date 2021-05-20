/*
* Implementation of selectRadioTask()
*
* This tasks job is to generate with the help of a rotary encoder the index
* to display a radio stations name. After pressing the encoder's switch the
* index is then used to change to that radio station.
* Display and change of the radio station are handled in a separate task.
*/
#include <tasksConfig.h>
//#include <radioStations.h>
//#include <stdint.h>     // for uint8_t


void selectRadioTask(void *param)
{
  Serial.printf("\n--- 1. Select Radio Task ---\n");

  // for-ever-loop
  // =============
  //
  for (;;)
  {
    // Serial.printf("--- 2. Select Radio Task ---\n");

    if (sMutex != NULL)
    {
      if (xSemaphoreTake(sMutex, (TickType_t) 10) == pdTRUE)
      {
        Serial.printf("Select Radio Station: %d pressed:%d\n",
                                coder.index, coder.select);

        //processRadioSelection(pCoder);

        xSemaphoreGive(sMutex);
      }

    } // end if-mutex

    // Serial.printf("\nRadio Station: %d pressed:%d\n",
    //                         coder.index, coder.select);

    vTaskDelay(1000 / portTICK_PERIOD_MS);

  } // end for-ever-loop()

}   // end selectRadioTask()

/*
* Laad aan de hand van pCoder->index de betreffende struct met radio
* station gegevens uit de array met radio stations.
* Als een radio station is geselecteerd: if (pCoder.select)
*   Maak contact met dat radio station en speel het af
*   Dit is een actie die we overdragen aan een andere task
* else
*   Als indexOudRadioStation != indexNewRadioStation
*       Laad de struct met gegevens van het nieuwe radio station
*       Toon de naam van het radio station
*   end
* end
*/
// void processRadioSelection(struct Coder *pCoder)
// {
//     Serial.printf("\nRadioStat.host: %s\n", sRadioStat[pCoder->index].host);
//     Serial.printf("RadioStat.path: %s\n", sRadioStat[pCoder->index].path);
//     Serial.printf("RadioStat.port: %d\n", sRadioStat[pCoder->index].port);
//     Serial.printf("RadioStat.name: %s\n", sRadioStat[pCoder->index].name);
//     Serial.printf("RadioStat.meta: %d\n", sRadioStat[pCoder->index].meta);

// }   // end processRadioSelection()
