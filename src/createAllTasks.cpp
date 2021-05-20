#include <stdlib.h>
#include <tasksConfig.h>

void createAllTasks()
{
    // All xTaskCreate... goes here and utilize the macros created
    // in taskConfig.h

    // Be very carefull about the ordening of tasks because they 
    // start running as soon as they're created.

    xTaskCreatePinnedToCore(
        rotaryEncoderTask,
        "Rotary Encoder Task",
        2048,
        NULL,
        1,
        NULL,
        1);

    xTaskCreatePinnedToCore(
        selectRadioTask,
        "Select Radio Task",
        4096,
        NULL,
        1,
        NULL,
        1);
     
}   // end createAllTasks()
