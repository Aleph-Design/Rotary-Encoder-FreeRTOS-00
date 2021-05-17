/*
* Protype and other specific for this task
*/

#ifndef ROTARY_ENCODER_TASK_H
#define rotaryEncoderTask_h

#define pin_CLK   26
#define pin_DT    27
#define pin_SW    14
#define MAX_INDEX 10
#define ENC_STEPS  4

// Define the semaphore here and give it a value in main.cpp so it
// can be used in this task.
//
extern SemaphoreHandle_t sMutex;

// These are the only valid steps when:
// coder pin_A [pin_CLK] H  L  L  H  H
// coder pin_B [pin_DT]  H  H  L  L  H
//	CW encoder movement: 3->1->0->2->3
// CCW encoder movement: 3<-1<-0<-2<-3
// 
// The 4 encoder steps between each detent are 
// represented in the STATE_MATRIX array below:
//					  newState =
//					  0   1   2   3
//	oldState = 0 => { 0, -1,  1,  0},
//	oldState = 1 => { 1,  0,  0, -1},
//	oldState = 2 => {-1,  0,  0,  1},
//	oldState = 3 => { 0,  1, -1,  0}
//
// int STATE_MATRIX[4][4] = {
// 		{ 0, -1,  1,  0},
// 		{ 1,  0,  0, -1},
// 		{-1,  0,  0,  1},
// 		{ 0,  1, -1,  0}
// };

void rotaryEncoderTask(void *param);

#endif