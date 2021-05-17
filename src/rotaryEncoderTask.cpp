/*
* Implementation of rotaryEncoderTask()
*
* This tasks job is to generate with the help of a rotary encoder the index
* to display a radio stations name. After pressing the encoder's switch the
* index is then used to change to that radio station.
* Display and change of the radio station are handled in a separate task.
*/
#include <tasksConfig.h>
#include <stdint.h>     // for uint8_t

void rotaryEncoderTask(void *param)
{
    uint8_t pin_A, pin_B, oldState, newState, oldCoderIndex, newCoderIndex;
    long int dirIndex = 0;	// signed integer

    // The purpose and use of this array is explained in the docs. And more
    // or less in rotaryEncoderTask.h
    //
    int STATE_MATRIX[4][4] = {
            { 0, -1,  1,  0},
            { 1,  0,  0, -1},
            {-1,  0,  0,  1},
            { 0,  1, -1,  0}
    };

    // From one detent to another there are 4 steps
    //
    pin_B = digitalRead(pin_DT);		// pin_B = 0 | 1
    pin_A = digitalRead(pin_CLK);		// pin_A = 0 | 1

    oldState = (pin_B | (pin_A << 1)); 	// CW: 3, 1, 0, 2, 3
    oldCoderIndex = 0;
    newCoderIndex = 0;

    // For-Ever-Loop
    // =============
    //
    for(;;)
    {
        pin_B = digitalRead(pin_DT);		// pin_B = 0 | 1
        pin_A = digitalRead(pin_CLK);		// pin_A = 0 | 1
        newState = (pin_B | (pin_A << 1)); 	// 3, 1, 0, 2 
      
        if (oldState != newState)
        {
            // The encoder has been rotated. Between each detent it runs through 
            // all ENC_STEPS. While turning right [CW] incrementing dirIndex.
            //
            dirIndex += STATE_MATRIX[oldState][newState];
            //Serial.printf("dirIndex: %ld\n", dirIndex);

            if (newState == 3)
            { 
                // newCoderIndex * 4 = dirIndex
                //
                newCoderIndex = (dirIndex >> 2);
                //Serial.printf("1. newCoderIndex: %d dirIndex: %ld\n\n", 
                //                              newCoderIndex, dirIndex);
                
                // The occurence of -ENC_STEPS takes place when rotating the 
                // coder CCW. Then newCoderIndex should change from MAX_INDEX 
                // to (MAX_INDEX -1) and when rotating CCW continues, it should
                // remain counting down.
                //
                if (dirIndex == -ENC_STEPS) 
                {
                    newCoderIndex = MAX_INDEX;
                    dirIndex      = MAX_INDEX * ENC_STEPS;
                }

                if (newCoderIndex > MAX_INDEX) 
                {
                    newCoderIndex = 0;
                    dirIndex      = 0;
                }
                
                if (oldCoderIndex != newCoderIndex)
                {
                    // This is the value of newCoderIndex we can use as index
                    // to select a new radio station.
                    //
                    // Here we can switch to another task to update the display
                    // of a radio stations name. We protect this with a mutex.
                    //
                    //Serial.printf("2. index new Radio Station: %d\n\n", 
                     //                                       newCoderIndex); 
                    if (sMutex != NULL)
                    {
                        if (xSemaphoreTake(sMutex, (TickType_t) 10) == pdTRUE)
                        {
                            coder.index  = newCoderIndex;  
                            coder.select = false;                                                                     
                            // When done
                            xSemaphoreGive(sMutex);

                            // taskYIELD() is used to request a context switch 
                            // to another task. 
                            taskYIELD();
                        }
                        // If the semaphore could not be obained within 10 ticks
                        // just move on.
                    }   // end if sMutex

                    oldCoderIndex = newCoderIndex;

                }   // end if oldCoderIndex

            }	// end if (newState == 3)

            oldState = newState;

        }	// end if (oldState != NewState)

        // Check for an encoder switch pressed to change to another radio
        // station.
        //
        if (digitalRead(pin_SW) == LOW)
        {
            // In here we must switch to another task to update the change
            // to another radio station. We protect this with a mutex
            //Serial.printf("\nSelect new Radio Station Pressed: %d\n\n", 
              //                                              newCoderIndex);
            vTaskDelay(300 / portTICK_PERIOD_MS);

            if (sMutex != NULL)
            {
                if (xSemaphoreTake(sMutex, (TickType_t) 10) == pdTRUE)
                {
                    coder.select = true;                                                                       
                    // When done
                    xSemaphoreGive(sMutex);

                    // taskYIELD() is used to request a context switch 
                    // to another task. 
                    taskYIELD();
                }
                // If the semaphore could not be obained within 10 ticks
                // just move on.
            }   // end if sMutex

        }   // if end digitalRead()

    }   // end for-ever-loop()
    
}   // rotaryEncoderTask(void *param)


// bool selectSwitchPressed()
// {
//     return (switchState == LOW);
// }

