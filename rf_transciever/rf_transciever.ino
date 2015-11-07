#include <SoftwareSerial.h>

//Use only one of these at a time when you upload the file.
//#define TRANSMITTER
#define RECEIVER

SoftwareSerial mySerial(0, 1); // RX, TX

#ifdef TRANSMITTER
  byte counter;

  void setup() {
    //using 2400 baud
    Serial.begin(1200);
    counter = 0;
  }
  
  void loop() {  
    //send to transmitter
    Serial.print(counter);
    counter++;
    delay(1000);
  }
#endif //TRANSMITTER
 
#ifdef RECEIVER
  int incomingByte = 0;

  void setup() {
    Serial.begin(1200);  
  }
  
  void loop() {
    //read in values, debug to computer
    if (Serial.available() > 0) {
      incomingByte = Serial.read();
      Serial.println(incomingByte, DEC);
    }
    incomingByte = 0;
  }
#endif //RECEIVER
