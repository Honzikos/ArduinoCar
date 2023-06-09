#include <IRremote.h>
IRrecv IR(9);
int motor2pin1 = 3;
int motor2pin2 = 4;
int motor1pin1 = 5;
int motor1pin2 = 2;



void setup() {
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);  
    IR.enableIRIn();
    Serial.begin(9600);
}


void loop() {
   if(IR.decode()) {  
      Serial.println(IR.decodedIRData.decodedRawData, HEX);
      IR.resume();
    } 
     
   
    if(IR.decodedIRData.decodedRawData == 0xE718FF00)//dopředu 0xE718FF00
    {
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      IR.resume();
      delay(1);
   }  
    if(IR.decodedIRData.decodedRawData == 0xA55AFF00)//doprava 0xA55AFF00
    {
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      IR.resume();
      delay(1);
   }   
    if(IR.decodedIRData.decodedRawData == 0xF708FF00)//doleva 0xF708FF00
    {
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      IR.resume();
      delay(1);
   }   
   
   if(IR.decodedIRData.decodedRawData == 0xE31CFF00)//všechny motory se vypnou 0xE31CFF00
   {
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, LOW);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      IR.resume();
      delay(1);
   }
    if(IR.decodedIRData.decodedRawData == 0xAD52FF00)//dozadu 0xF708FF00
    {
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      IR.resume();
      delay(1);
   }      
}
