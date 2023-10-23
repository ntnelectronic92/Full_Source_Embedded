#ifndef GLOBAL_H
#define GLOBAL_H
#include "main.h"
extern uint8_t hours ;
extern uint8_t minutes;
extern uint8_t second;
typedef enum
{
  Mode_Minute,
  Mode_Hour,
  Mode_Idle,
} ModeChange;
extern ModeChange _mode;
extern unsigned long timeGet1S;
extern unsigned long reduceFlick;
extern bool valueDisplayHour;
extern bool valueDisplayMinutes;
extern const char * stringViewFormat;
extern const char * stringViewFormatNoneSecond;
#endif