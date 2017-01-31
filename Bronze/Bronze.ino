int RED[160];
int GREEN[160];
int BLUE[160];
int count;
boolean raise = true;
boolean TEAM = false;
const int buttonPin=6;
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
      RED[i] = 10;
      BLUE[i] = 10;
      GREEN[i] = 10;
    }
  }

void updatestring() {
    for(int i; i<160;i++){
      shiftOut(datapin, clockpin, MSBFIRST, BLUE[i]);
      shiftOut(datapin, clockpin, MSBFIRST, GREEN[i]);
      shiftOut(datapin, clockpin, MSBFIRST, RED[i]);
    
      }
    }
boolean pressed = false;
void loop() {
   int b = digitalRead(buttonPin);
   if(b==LOW&& pressed==false)
   {
    TEAM = !TEAM;
    pressed = true;
    }
    else if(b!=LOW&&pressed==true)
    pressed = false;
  for (int i; i < 10; i++) {
    color();

  }
  alpha++;
}

void color() {
  
  int a = (alpha + 1) % 3;
  int b = (alpha) % 3;
  bright = brightness(bright);
  if(TEAM){
  for (int i; i < 160; i++) {
    if (i % 3 == a || i % 3 == b) {
      RED[i] = bright;
      GREEN[i] = 35;
      BLUE[i] = 3;
    } else {

      RED[i] = 0;
      GREEN[i] = 25;
      BLUE[i] = 30;
    }
  }
  } else {
    for (int i; i < 160; i++) {
    if (i % 3 == a || i % 3 == b) {
      RED[i] = 15;
      GREEN[i] = 39;
      BLUE[i] = bright;
    } else {

      RED[i] = 80;
      GREEN[i] = 35;
      BLUE[i] = 3;
    }
  }
  }
  updatestring();
  delay(10);
}

int brightness(int bright) {
int gamma = 0;
if(TEAM)
gamma = 220;
else
gamma = 250;
  if (raise && bright < gamma)
    bright += 5; 
  else if (raise)
  {
    raise = false; 
    bright -= 5; 
  } else if (bright > 70) 
    bright -= 5; 
  else 
  {
    raise = true; 
    bright += 5; 
  }
  return bright;  
}
