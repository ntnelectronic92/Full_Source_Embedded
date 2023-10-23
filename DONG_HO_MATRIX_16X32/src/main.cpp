#include "main.h"

void setup()
{
  Serial.begin(115200);
  user_app_init();
}

void loop() 
{
  user_app_handler();
}
