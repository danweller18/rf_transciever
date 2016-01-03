// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;
String message;

void setup() {
  Serial.begin(9600);	// Debugging only
  message = "";
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  // Message with a good checksum received, dump it.
  if (driver.recv(buf, &buflen)) { // Non-blocking
    //define variables
    const uint8_t* thebuf = buf;
    uint8_t len = buflen;
    uint8_t i;
  
    #ifdef RH_HAVE_SERIAL
      Serial.println("Got:");
      for (i = 0; i < len; i++) {
        if (i % 16 == 15) {
          message += char(thebuf[i]);
          Serial.println(char(thebuf[i]));
        } else {
          Serial.print(char(thebuf[i]));
          Serial.print(' ');
          message += char(thebuf[i]);
        }
      }
      Serial.println("");
    #endif
    
    Serial.println(message);
  }
}
