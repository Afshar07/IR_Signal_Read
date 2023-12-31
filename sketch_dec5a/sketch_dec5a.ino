#include <IRLibRecvPCI.h> 

IRrecvPCI myReceiver(2);//pin number for the receiver


void setup() {

Serial.begin(9600);

 myReceiver.enableIRIn();

 Serial.println(F("Ready to receive IR signals"));

}

void loop() {
  // put your main code here, to run repeatedly:
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) { 
    // Serial.println(F("Do a cut-and-paste of the following lines into the "));
    // Serial.println(F("designated location in rawSend.ino"));
    Serial.print(F("\n#define RAW_DATA_LEN "));
    Serial.println(recvGlobal.recvLength,DEC);
    Serial.print(F("uint16_t rawData[RAW_DATA_LEN]={\n\t"));
    for(bufIndex_t i=1;i<recvGlobal.recvLength;i++) {
      Serial.print(recvGlobal.recvBuffer[i],DEC);
      Serial.print(F(", "));
      if( (i % 8)==0) Serial.print(F("\n\t"));
    }
    Serial.println(F("};"));//Add arbitrary trailing space
    myReceiver.enableIRIn();  

    }
  }