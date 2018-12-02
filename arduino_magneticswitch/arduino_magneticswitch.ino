/*
 * Script to read the value of the magnetics switch (connected to GND and a digital pin)
 * 
 * Tested on:
 *  Arduino Uno
 *  Wemos D1 Mini
 * 
 * Pin configuration for WeMos: https://wiki.wemos.cc/products:d1:d1_mini
 * (D8 did not work, with D4 the built-in led turns on when door is closed, which is maybe not what we need
 */


const int sensor = D4; // For Arduino Uno: 4

int state; // 0 close - 1 open
int prevState = -1;

void setup()
{
  pinMode(sensor, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop()
{
  state = digitalRead(sensor);

  if (prevState != state) {
    prevState = state;
    if (state == HIGH){
        Serial.println(1); // door is open
      }
      else{
        Serial.println(0); // door is closed
      }
  }
  
  delay(200);
}
