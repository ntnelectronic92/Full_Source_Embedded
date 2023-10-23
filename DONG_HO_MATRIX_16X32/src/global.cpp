#include "global.h"

uint8_t hours = 0;
uint8_t minutes = 0;
uint8_t second = 0;
ModeChange _mode= Mode_Idle;
unsigned long timeGet1S = 0;
unsigned long reduceFlick = 0;
bool valueDisplayHour = true;
bool valueDisplayMinutes = true;
const char * stringViewFormat = "%02d:%02d";
const char * stringViewFormatNoneSecond = "%02d %02d";