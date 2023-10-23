#include "user_RGBMatrix.h"

RGBmatrixPanel matrix(A_ROW, B_ROW, C_ROW, CLK_PIN, LAT_PIN, OE_PIN, false);

char str[6] = "20:01";
int16_t hue = 0;
int8_t ball[3][4] = {
  {3, 0, 1, 1},
  {17, 15, 1, -1},
  {27, 4, -1, 1}
};
static const uint16_t PROGMEM ballcolor[3] = {
  0x0080, // Green=1
  0x0002, // Blue=1
  0x1000  // Red=1
};
void user_RGBMatrix_Init()
{
    matrix.begin();
    matrix.setTextWrap(true);
    matrix.setTextSize(1);
}
void mergeViewHandle()
{
    if (second % 2 == 0) 
    {
      if(_mode == Mode_Hour && !valueDisplayHour)
      {
         sprintf(str,stringViewFormat,minutes);
      }
      else
      {
        sprintf(str,stringViewFormat,hours,minutes);
      }
    } 
    else 
    {
      if(_mode == Mode_Hour && !valueDisplayHour)
      {
         sprintf(str,stringViewFormatNoneSecond, minutes);
      }
      else
      {
        sprintf(str,stringViewFormatNoneSecond,hours,minutes);
      }
    }
}
void user_DisplayTextAndBallHandle()
{
  long long static reduceFlick = millis();
  if (millis() - reduceFlick > 20) 
  {
    reduceFlick = millis();
    DateTime now = rtc.now();
    if(_mode == Mode_Idle)
    {
      hours = now.hour();
      minutes = now.minute();
    }
    second = now.second();
    mergeViewHandle();
    hue += 7;
    if (hue >= 1536) hue -= 1536;
    matrix.setTextColor(matrix.ColorHSV(hue, 200, 200, true));
    matrix.fillScreen(0);
    for (int i = 0; i < 3; i++) 
    {
      matrix.fillCircle(ball[i][0], ball[i][1], 3, pgm_read_word(&ballcolor[i]));
      ball[i][0] += ball[i][2];
      ball[i][1] += ball[i][3];
      if ((ball[i][0] == 0) || (ball[i][0] == (matrix.width() - 1))) ball[i][2] *= -1;
      if ((ball[i][1] == 0) || (ball[i][1] == (matrix.height() - 1))) ball[i][3] *= -1;
    }
  }
  matrix.setCursor(2, 4); 
  matrix.print(str);

}