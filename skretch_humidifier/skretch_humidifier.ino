#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL, 8);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void myOLEDscreenupd();


void setup() {

  myOLED.begin();
  myOLED.setFont(SmallFont);

  Serial.begin(9600);
}

void loop() {






  myOLEDscreenupd();
}


void myOLEDscreenupd(){

  myOLED.clrScr();
/*
  myOLED.print({"Water level " + ver}, CENTER, 0);
  myOLED.print(Plant1_info, LEFT, 16); 
  myOLED.print(Plant2_info, LEFT, 26);
  myOLED.print(Plant3_info, LEFT, 36);
  myOLED.print(Plant4_info, LEFT, 46);
  myOLED.print({"Water saturation: "+ String(proc_water, DEC)+"%"}, LEFT, 56);
*/
  myOLED.update();
}


