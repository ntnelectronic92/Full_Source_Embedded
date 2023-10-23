#include "user_RTC_DS3231.h"
RTC_DS3231 rtc;
void user_RTC_DS3231_Init()
{
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("Không thể tìm thấy DS3231. Vui lòng kiểm tra kết nối.");
    while (1);
  }
  if (rtc.lostPower())
   {
    Serial.println("DS3231 mất điện trước đó. Đặt thời gian lại.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}


