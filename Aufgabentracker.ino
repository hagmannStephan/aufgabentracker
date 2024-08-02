#include <LiquidCrystal.h>

int switchStateNext = 0;
int switchStateDone = 0;

int currentTask = 0;    // Track which task is currently being displayed

class Task {
private:
    String title;
    int value;      // CHF
    String repeat; // daily
    int duration;   // minutes

public:
    // Constructor
    Task(const String& title, int value, const String& repeat, int duration)
        : title(title), value(value), repeat(repeat), duration(duration) {}

    // Getters
    String getTitle() const { return title; }
    int getValue() const { return value; }
    String getRepeat() const { return repeat; }
    int getDuration() const { return duration; }
};

Task tasks[] = {
    Task("Play Guitar", 25, ".", 20),
    Task("Draw", 30, ".", 20)
};

const int numTasks = sizeof(tasks) / sizeof(tasks[0]);

// LCD pins <--> Arduino pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void printTask(int num)
{
  lcd.clear();

  // TODO: Only display current tasks
  lcd.setCursor(0, 0);
  lcd.print(tasks[num].getTitle());
  
  lcd.setCursor(0, 1);
  lcd.print(tasks[num].getDuration());
  lcd.print(" min");

  lcd.setCursor(10, 1);
  lcd.print(tasks[num].getValue());
  lcd.print(" CHF"); 
}


void setup()
{
  lcd.begin(16, 2);

  printTask(0);

  // INPUT_PULLUP because INPUT doesn't work with two buttons
  pinMode(6, INPUT_PULLUP);   // done button
  pinMode(7, INPUT_PULLUP);   // next button
}

void loop()
{

  switchStateDone = digitalRead(6);   // Read state of buttons
  switchStateNext = digitalRead(7);

  if (switchStateNext == HIGH) {
    currentTask = (currentTask + 1) % numTasks;
    printTask(currentTask);
    delay(300); // Debounce delay to prevent multiple reads
  }
}
