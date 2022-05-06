#include "HID-Project.h"

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D55 55

void setup() {
  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLUP);
  pinMode(D6, INPUT_PULLUP);
  pinMode(D7, INPUT_PULLUP);
  pinMode(D8, INPUT_PULLUP);
  pinMode(D9, INPUT_PULLUP);
  pinMode(D10, INPUT_PULLUP);
  Consumer.begin();
}

void loop() {
  //Consumer.write(MEDIA_VOLUME_UP);
  //Serial.println("test1");
  if (digitalRead(D0) == LOW)
  {
     Serial.println("D0");
  }
  if (digitalRead(D1) == LOW)
  {
     Serial.println("D1");
  }
  if (digitalRead(D2) == LOW)
  {
     Serial.println("D2");
  }
  if (digitalRead(D3) == LOW)
  {
     Serial.println("D3");
  }
  if (digitalRead(D4) == LOW)
  {
     Serial.println("D4");
  }
  if (digitalRead(D5) == LOW)
  {
     Serial.println("D5");
  }
  if (digitalRead(D6) == LOW)
  {
     Serial.println("D6");
  }
  if (digitalRead(D7) == LOW)
  {
     Serial.println("D7");
  }
  if (digitalRead(D8) == LOW)
  {
     Serial.println("D8");
  }
  //Serial.println("test2");
  //delay(2000);
  //Consumer.write(MEDIA_VOLUME_DOWN);
  //delay(2000);
}
