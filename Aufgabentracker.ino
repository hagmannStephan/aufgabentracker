#include <LiquidCrystal.h>

int switchStateNext = 0
int switchStateDone = 0

// LCD pins <--> Arduino pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); // set up number of columns and rows

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)

  pinMode(8, OUTPUT);     // green LED
}

void loop()
{
  digitalWrite(8, HIGH);
}
