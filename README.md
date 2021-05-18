# Rotary-Encoder-FreeRTOS-00
First exercise in distributing the generation of radio station indexes over separate tasks in FreeRTOS.

This project now has:
1.  A reasonable separation of FreeRTOS task functions and header files.
2.  Use of a mutex to "transport" values that are hold in a struct over multiple tasks.
3.  A clear insight into how to define, declare, initialize and use local- and global variables in a project that has several header and program files.

