
#include "Arduino.h"

#ifndef GsBtnClass_h
#define GsBtnClass_h

class Button {
  private:
    int debounceDelay;

  public: 
    static int pin;
    static int isPressed;
    static int wasPressed;
    static long lastPressTime;
    bool state();
    Button(int PIN, int DEBOUNCE_DELAY);

};

#endif
