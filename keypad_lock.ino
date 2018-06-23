// How to Make an Arduino Keypad Lock
// Jlaservideo.com

#include <Servo.h>
#include <Keypad.h>

Servo ServoMotor;
char* password ;  // change the password here, just pick any 3 numbers
int position = 0;
int wInputCount = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
                          {'1','2','3','A'},
                          {'4','5','6','B'},
                          {'7','8','9','C'},
                          {'*','0','#','D'}
                          };

byte rowPins[ROWS] = { 8, 7, 6, 5 };
byte colPins[COLS] = { 4, 3, 2, 1 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  LockedPosition(true);
  Serial.begin(9600); 
  Serial.println("Press please");
}

void loop()
{
  char key = keypad.getKey();
  if(key)
  {
      if (key == '*')
      {
        for(int i = 0; i<password.length; i++)
          password[i] = char(0);
        char key = keypad.getKey();
        if(key)
      }
      else
      {
        
      }
  }
  delay(100);
}
void LockedPosition(boolean locked)
{
  if (locked)
  {
//    digitalWrite(RedpinLock, HIGH);
//    digitalWrite(GreenpinUnlock, LOW);
//    ServoMotor.write(11);
      Serial.println("Locked");
  }
  else
  {
//  digitalWrite(RedpinLock, LOW);
//  digitalWrite(GreenpinUnlock, HIGH);
//  ServoMotor.write(90);
    Serial.println("Unlocked");
    position = 0;
    wInputCount = 0;
  }
}
void callOwner()
{
  Serial.println("Calling...");
  wInputCount = 0;
}


