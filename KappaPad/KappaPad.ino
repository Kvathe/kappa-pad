

#include <CapacitiveSensor.h>
#include <Keyboard.h>

#include "CapacitiveKey.h"

//#define SERIAL_OUTPUT
#define DISABLE_PIN 15

void setup() {
  #ifdef SERIAL_OUTPUT
  Serial.begin(115200);
  #endif
  Keyboard.begin();
  pinMode(DISABLE_PIN, INPUT_PULLUP);
}

CapacitiveKey key1 = CapacitiveKey(
  3,    //Capacitive Send Pin
  7,    //Capacitive Sense Pin
  10,   //LED Pin
  6,    //Capacitive Threshold
  'z',  //Keyboard Key
  255   //LED Brightness (0-255)
);
CapacitiveKey key2 = CapacitiveKey(
  2,    //Capacitive Send Pin
  6,    //Capacitive Sense Pin
  10,   //LED Pin
  5,    //Capacitive Threshold
  'x',  //Keyboard Key
  255   //LED Brightness (0-255)
);
CapacitiveKey key3 = CapacitiveKey(
  A2,    //Capacitive Send Pin
  14,    //Capacitive Sense Pin
  10,   //LED Pin
  5,    //Capacitive Threshold
  'c',  //Keyboard Key
  255   //LED Brightness (0-255)
);
CapacitiveKey key4 = CapacitiveKey(
  A3,    //Capacitive Send Pin
  15,    //Capacitive Sense Pin
  10,   //LED Pin
  5,    //Capacitive Threshold
  'v',  //Keyboard Key
  255   //LED Brightness (0-255)
);

void loop() {
  bool keyboardActive = digitalRead(DISABLE_PIN);
  key1.keyUpdate(keyboardActive);
  key2.keyUpdate(keyboardActive);
  key3.keyUpdate(keyboardActive);
  key4.keyUpdate(keyboardActive);

  #ifdef SERIAL_OUTPUT
  Serial.print(key1.sample);
  Serial.print(",");
  Serial.print(key2.sample);
  Serial.print(",");
  Serial.print(key3.sample);
  Serial.print(",");
  Serial.print(key4.sample);
  #endif
}


