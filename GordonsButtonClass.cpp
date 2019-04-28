
#include "Arduino.h"
#include "GordonsButtonClass.h"

Button::Button(int PIN, int DEBOUNCE_DELAY) {
  pin = PIN;
  pinMode(PIN, INPUT);
  debounceDelay = DEBOUNCE_DELAY;
  isPressed = false;
  wasPressed = false;
  lastPressTime = 0;
}

bool Button::state() {

  isPressed = digitalRead(pin);

  if (isPressed && !wasPressed) {        
    // if button is pressed now but is wasnt last time
    lastPressTime = millis();

  } else if (!isPressed && wasPressed) {              
    // if the button is not pressed now but it was last time

    if (millis() - lastPressTime > debounceDelay) { 
      return true;
    }    
  }

  wasPressed = isPressed;
  return false;
}
