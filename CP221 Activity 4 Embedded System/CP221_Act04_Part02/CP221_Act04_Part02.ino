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
    int command = IrReceiver.decodedIRData.command ;

    if (command == 69) Serial.println("Pressed CH-") ; 
    else if (command == 69) Serial.println("Pressed CH-") ; 
    else if (command == 70) Serial.println("Pressed CH") ; 
    else if (command == 71) Serial.println("Pressed CH+") ; 
    else if (command == 68) Serial.println("Pressed |<<") ; 
    else if (command == 64) Serial.println("Pressed >>|") ; 
    else if (command == 67) Serial.println("Pressed >||") ; 
    else if (command == 7) Serial.println("Pressed -") ; 
    else if (command == 21) Serial.println("Pressed +") ; 
    else if (command == 9) Serial.println("Pressed EQ") ;
    else if (command == 22) Serial.println("Pressed 0") ; 
    else if (command == 25) Serial.println("Pressed 100+") ; 
    else if (command == 13) Serial.println("Pressed 200+") ; 
    else if (command == 12) Serial.println("Pressed 1") ; 
    else if (command == 24) Serial.println("Pressed 2") ; 
    else if (command == 94) Serial.println("Pressed 3") ; 
    else if (command == 8) Serial.println("Pressed 4") ; 
    else if (command == 28) Serial.println("Pressed 5") ; 
    else if (command == 90) Serial.println("Pressed 6") ; 
    else if (command == 66) Serial.println("Pressed 7") ; 
    else if (command == 82) Serial.println("Pressed 8") ; 
    else if (command == 74) Serial.println("Pressed 9") ; 

  }
}
