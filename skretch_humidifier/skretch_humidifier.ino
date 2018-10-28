#include <OLED_I2C.h>
#include <DHT11.h>

OLED  myOLED(SDA, SCL, 8); // A4, A5

extern uint8_t SmallFont[];
extern uint8_t MediumFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void myOLEDscreenupd(float, float);   // function for OLED update information

#define DHTPIN 2          // data pin from DHT11
#define DHTTYPE DHT11     // Type of DHT
DHT dht(DHTPIN, DHTTYPE); // define sensor



void setup() {

  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.invert(1); // inversion of OLED

  dht.begin();

  Serial.begin(9600);
  
  
}






void loop() {

  // Reading temp and humidity from sensor, delay of this operation is 250ms
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temp: ");
  Serial.println(t);  

  myOLEDscreenupd(h, t);
}


void myOLEDscreenupd(float h, float t){

  int height_hum_txt  = 5;
  int height_temp_txt = 36;


  myOLED.clrScr();
  
  myOLED.setFont(SmallFont);
  myOLED.print({"Humidity is, %:"}, CENTER, height_hum_txt);
  myOLED.setFont(MediumNumbers);
  myOLED.print({String(h, 2)}, CENTER, height_hum_txt + 9);

  myOLED.setFont(SmallFont);
  myOLED.print({"Temperature is: "}, CENTER, height_temp_txt);
  myOLED.setFont(MediumNumbers);
  myOLED.print({String(t, 2)}, CENTER, height_temp_txt + 9);

/*
  myOLED.print(Plant1_info, LEFT, 16); 
  myOLED.print(Plant2_info, LEFT, 26);
  myOLED.print(Plant3_info, LEFT, 36);
  myOLED.print(Plant4_info, LEFT, 46);
  myOLED.print({"Water saturation: "+ String(proc_water, DEC)+"%"}, LEFT, 56);
*/
  myOLED.update();
}


