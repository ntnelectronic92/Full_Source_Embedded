#include "user_app.h"

void user_modeHandle()
{
  switch (_mode)
  {
  case Mode_Idle:
     stringViewFormat =  "%02d:%02d";
     stringViewFormatNoneSecond = "%02d %02d";
    break;
  case Mode_Minute:
     static long valueGetTimeMinutes  = millis();

     if(millis() - valueGetTimeMinutes > 200)
     {
       valueGetTimeMinutes  = millis();
       valueDisplayMinutes=!valueDisplayMinutes;
       if(valueDisplayMinutes)
       {
        stringViewFormat = "%02d:%02d";
        stringViewFormatNoneSecond = "%02d %02d";
       }
       else
       { 
         stringViewFormat = "%02d:";
         stringViewFormatNoneSecond = "%02d";
       }
     }
     break;
  case Mode_Hour:
     static long valueGetTimeHour  = millis();
     if(millis() - valueGetTimeHour > 200)
     {
       valueGetTimeHour  = millis();
       valueDisplayHour=!valueDisplayHour;
       if(valueDisplayHour)
       {
        stringViewFormat = "%02d:%02d";
        stringViewFormatNoneSecond = "%02d %02d";
       }
       else
       {
         stringViewFormat = "  :%02d";
         stringViewFormatNoneSecond = "   %02d";
       } 
     }
     break;
  default:
    break;
  }
}