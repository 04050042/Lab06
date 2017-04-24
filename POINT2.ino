#include <Key.h>
#include <Keypad.h>

#define KEY_ROWS 4 
#define KEY_COLS 4 
int tune[] = { 261,294,329,349,
392, 440, 493,523,
523,587,659,698,
784,880,988,1046
};
 
char keymap[KEY_ROWS][KEY_COLS] = {
  {'0', '4', '8', 'C'},
  {'1', '5', '9', 'D'},
  {'2', '6', 'A', 'E'},
  {'3', '7', 'B', 'F'}};
  
byte colPins[KEY_COLS] = {9,8,7,6};
byte rowPins[KEY_ROWS] = {5,4,3,2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);

void setup()
{
  Serial.begin(9600);
  byte numDigits = 1;
  byte digitPins[] = {10};
  byte segmentPins[] = {A0,A1,A4,A3,A2,12,A5,13};
}

void loop()
{
    char x=myKeypad.getKey();
    if (x != NO_KEY)
    {
      if(x>='0' && x<='9')
      {
        tone(10, tune[x-48]);
        delay(300);
        noTone(10);
      }
      if(x>='A' && x<='F')
      {
        tone(10, tune[x-55]);
        delay(300);
        noTone(10);
      }
    }
}
