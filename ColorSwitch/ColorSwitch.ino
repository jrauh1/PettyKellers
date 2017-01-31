//create arrays
int RED[160];
int GREEN[160];
int BLUE[160];
//int count;
int r = 0, g = 0, b = 0;
//
//pin map

const int buttonPin=7;
int clockpin = 2;
int datapin = 1;
//
//setup code
void setup()
{
 
  pinMode(buttonPin, INPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  for (int i=0;i<160;i++)
  {                 
    RED[i]=0;
    BLUE[i]=0;
    GREEN[i]=0;
  }
}
//
void updatestring()
{
for(int i=0;i<160;i++)
{
shiftOut(datapin, clockpin, MSBFIRST, BLUE[i]);
shiftOut(datapin, clockpin, MSBFIRST, GREEN[i]);
shiftOut(datapin, clockpin, MSBFIRST, RED[i]);
}
}
//
// boolean pressed = true;
  //boolean color = true;



boolean pressed = false;
void loop()
{

 int b = digitalRead(buttonPin);
  if(b==LOW&&pressed)
  {
    r = 100;
    g = 0;   
    b = 0;
    pressed = true;
  }
  else
  {
    r = 0;
    g = 255;
    b = 0;
    pressed = false;
  }

  
for(int i=0;i<160;i++)
{

  

RED[i]=r;GREEN[i]=g;BLUE[i]=b;

//RED[i]=200;GREEN[i]=200;BLUE[i]=200;
// As the lights progress color becomes more reddish


}
updatestring();
delay(1);


}
