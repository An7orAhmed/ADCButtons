
class ADCButton {
  private:
    byte _pin;
    char *_key;

  public:
    ADCButton(byte pin);

    byte get() {
      int adc = analogRead(_pin);
      switch (adc) {
        case 1014 ... 1020: return 1;
        case 1006 ... 1012: return 2;
        case 999 ... 1005: return 3;
        case 990 ... 996: return 4;
        case 984 ... 989: return 5;
        case 977 ... 983: return 6;
        case 957 ... 963: return 7;
        case 928 ... 934: return 8;
        case 890 ... 896: return 9;
        case 836 ... 842: return 10;
        case 777 ... 783: return 11;
        case 761 ... 765: return 12;
        case 702 ... 708: return 13;
        case 659 ... 665: return 14;
        case 612 ... 618: return 15;
        case 566 ... 572: return 16;
        default: return 0;
      }
      return 0;
    }

    char getKeyChar() {
      int key = get();
      if (key == 0) return 0;
      return _key[key - 1];
    }

    char waitForKey() {
      char key = getKeyChar();
      while (!key) key = getKeyChar();
      return key;
    }
};

ADCButton button(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte b = button.get();
  char k = button.getKeyChar();
  if (b != 0) {
    Serial.print(b);
    Serial.print("  ");
    Serial.println(k);
  }
}
