#include <IRremote.h>
#define IR_RECEIVE_PIN 11

// 1. สร้างตัวแปร Global ไว้เก็บค่ารวม (ไว้นอก loop)
double currentValue = 0; 

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    
    // กรองพวกค่า Repeat (เวลากดค้าง) ออกก่อน เพื่อไม่ให้เลขเบิ้ลรัวๆ
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
      IrReceiver.resume();
      return;
    }

    int command = IrReceiver.decodedIRData.command;
    int digit = -1; // สมมติให้ -1 คือ "ไม่ใช่ตัวเลข"

    // 2. แปลง Code รีโมท เป็นตัวเลขจริงๆ (Integer)
    switch (command) {
      case 22: digit = 0; break; // แก้เลข case ตามรีโมทจริงของคุณ
      case 12: digit = 1; break;
      case 24: digit = 2; break;
      case 94: digit = 3; break;
      case 8:  digit = 4; break;
      case 28: digit = 5; break;
      case 90: digit = 6; break;
      case 66: digit = 7; break;
      case 82: digit = 8; break;
      case 74: digit = 9; break;
      
      case 25: // ปุ่ม EQ (สมมติ) ไว้กด Reset เป็น 0
        currentValue = 0;
        Serial.println("Reset!");
        break;
        
      default:
        // ถ้ากดปุ่มอื่นที่ไม่ใช่ตัวเลข
        break;
    }

    // 3. ถ้าเป็นตัวเลข (0-9) ให้เอามาต่อท้าย
    if (digit != -1) {
      currentValue = (currentValue * 10) + digit;
      Serial.println(currentValue); // แสดงผลลัพธ์ เช่น 5, 54, 543
    }

    IrReceiver.resume();
  }
}