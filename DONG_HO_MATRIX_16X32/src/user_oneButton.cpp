#include "user_oneButton.h"

OneButton buttonIncrease(11, true);
OneButton buttonMode(12, true);
OneButton buttonDecrease(13,true);

void buttonModePress()
{
  Serial.println("buttonModePress");
  valueDisplayHour = true;
  valueDisplayMinutes = true;
  switch (_mode)
  {
  case Mode_Idle:
    _mode = Mode_Minute;
    break;
  case Mode_Minute:
    _mode = Mode_Hour;
   break;
  case Mode_Hour:
    _mode = Mode_Idle;
    DateTime now = rtc.now();
    DateTime newTime(now.year(), now.month(), now.day(), hours, minutes, now.second());
    rtc.adjust(newTime);
    break;
  default:
    break;
  }

}
void buttonIncreasePress()
{
  Serial.println("buttonIncreasePress");
  switch (_mode)
  {
  case Mode_Idle:

    break;
  case Mode_Minute:
    minutes++;
    if(minutes >= 60)
    {
      minutes = 0;
    }
   break;
  case Mode_Hour:
    hours++;
    if(hours >= 24)
    {
      hours = 0;
    }
   break;
  default:
    break;
  }
}

void buttonDecreasePress()
{
  Serial.println("buttonDecreasePress");
  switch (_mode)
  {
  case Mode_Idle:

    break;
  case Mode_Minute:
    
    if(minutes == 0)
    {
      minutes = 59;
    }
    else
    {
      minutes--;
    }
   break;
  case Mode_Hour:
    if(hours == 0)
    {
      hours = 23;
    }
    else
    {
       hours--;
    }
   break;
  default:
    break;
  }
}
void user_oneButton_Init()
{
    buttonMode.attachClick(buttonModePress);
    buttonIncrease.attachClick(buttonIncreasePress);
    buttonDecrease.attachClick(buttonDecreasePress);
}
void user_oneButton_handler()
{
    buttonMode.tick();
    buttonIncrease.tick();
    buttonDecrease.tick();
}