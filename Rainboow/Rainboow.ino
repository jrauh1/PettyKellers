    int RED[160];
int GREEN[160];
int BLUE[160];
int count;
boolean raise = true;
boolean TEAM = false;
const int buttonPin = 6;
int bright = 80;
int alpha = 0;
//pin map
int clockpin = 2;
int datapin = 1;

/**setup code**/
void setup() {
  pinMode(buttonPin, INPUT);
  count = 0;
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  for (int i = 0; i < 160; i++) {
    RED[i] = 0;
    BLUE[i] = 0;
    GREEN[i] = 0;
  }
}

void updatestring() {
  for (int q; q < 160; q++) {
    shiftOut(datapin, clockpin, MSBFIRST, BLUE[q]);
    shiftOut(datapin, clockpin, MSBFIRST, GREEN[q]);
    shiftOut(datapin, clockpin, MSBFIRST, RED[q]);

  }
}
void loop() {
  unsigned int rgb[3];
  rgb[0] = 255;
  rgb[1] = 0;
  rgb[2] = 0;

  for (int decColor = 0; decColor < 3; decColor++) {
    int incColor = decColor == 2 ? 0 : decColor + 1;

    for (int i = 0; i < 255 / 15; i++) {
      rgb[decColor] -= 15;
      rgb[incColor] += 15;

      RED[0] = rgb[0];
      GREEN[0] = rgb[1];
      BLUE[0] = rgb[2];
      updatestring();
      delay(1);
      for (int c = 159; c >= 1; c--) {
        RED[c] = RED[c - 1];
        GREEN[c] = GREEN[c - 1];
        BLUE[c] = BLUE[c - 1];
      }

    }

  }

}
