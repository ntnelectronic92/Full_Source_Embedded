#ifndef USER_RGBMATRIX_H
#define USER_RGBMATRIX_H
#include "main.h"

#define LAT_PIN 8
#define CLK_PIN  9
#define OE_PIN   10

#define A_ROW A0
#define B_ROW A1
#define C_ROW A2
void user_RGBMatrix_Init();
void user_DisplayTextAndBallHandle();
#endif