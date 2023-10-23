#include "user_app.h"
void user_app_init()
{
    user_oneButton_Init();
    user_RGBMatrix_Init();
    user_RTC_DS3231_Init();
}

void user_app_handler()
{  
    user_oneButton_handler();
    user_DisplayTextAndBallHandle();
}