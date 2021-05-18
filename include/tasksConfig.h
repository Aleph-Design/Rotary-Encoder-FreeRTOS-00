/*
* Put all config for the whole project here.
* Define all macros for the project
*/
#ifndef TASKS_CONFIG_H
#define tasksConfig_h

#include <arduino.h>   // Equal to: #include <FreeRTOS.h>
#include <rotaryEncoderTask.h>

// A struct to "transport" variables to the task that is responsible for
// displaying a radio stations name indicated by "index" and to change to 
// the selected radio station when the encoder switch is pressed.
//
struct Coder {
    uint8_t index;      // index of this radio station to display
    bool    select;     // radio station with this index to play
};

// We want to access the variable "coder" in another file. 
// So, we ADDITIONALLY add a DECLARATION in a header file:
// The keyword extern basically says: “This is JUST a DECLARATION”.
// "coder" is initialized in rotaryEncoderTask.cpp
//
extern Coder coder; 

#endif