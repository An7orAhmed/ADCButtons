#ifndef ADCBUTTONS_H
#define ADCBUTTONS_H
#include <arduino.h>

class ADCButtons {
  private:
    byte _pin;
    char *_key;

  public:
    ADCButtons(byte pin);
    byte get();
    char getKeyChar();
    char waitForKey();
};

#endif