# include <IRremote.h>
#define IR_RECEIVE_PIN 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) { 
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command);
  }
}
