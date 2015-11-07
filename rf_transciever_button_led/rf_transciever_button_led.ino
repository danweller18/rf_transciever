#include <SoftwareSerial.h>

//Use only one of these at a time when you upload the file.
//#define TRANSMITTER
#define RECEIVER

SoftwareSerial mySerial(0, 1); // RX, TX

#ifdef TRANSMITTER
  int status;

  void setup() {
    Serial.begin(2400);
    status = 0;
  }
  
  void loop() {  
    //send to transmitter
    Serial.write(status);
    Serial.println(status);
    //change state for next loop
    if (status == 1) {
      status = 2;
    } else {
      status = 1;
    }
    delay(5000);
  }
#endif //TRANSMITTER
 
#ifdef RECEIVER
  int incomingStatus = 0;

  void setup() {
    Serial.begin(2400);  
    pinMode(13, OUTPUT);
  }
  
  void loop() {
    //read in values
    if (Serial.available() > 0) {
      incomingStatus = Serial.read();
      //if something has been sent flash led pin 13
      if (incomingStatus > 0) {
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13, LOW);
      }
      Serial.println(incomingStatus);
    }
    incomingStatus = 0;
  }
#endif //RECEIVER
