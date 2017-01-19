<<<<<<< HEAD
#define Ab3 207.65
#define C4  261.63
#define E4  329.63
#define F3  174.61
#define F4  349.23
#define LA3 220.00

#define Q 500
#define E Q/2
#define S Q/4
#define H Q*2

#define VCC 3 // VCC pin (3.3v)
#define GND 4 // GND pin (0.0v)
#define SPK 1 // speaker pin
#define RED 4 // led pin

// ---------------------------------------------------------------------------------

// Imperial March (partition)
unsigned int note[] = {LA3,LA3,LA3,F3,C4, LA3,F3,C4,LA3, E4,E4,E4,F4,C4, Ab3,F3,C4,LA3};
unsigned long duration[] = {Q,Q,Q,E+S,S, Q,E+S,S,H, Q,Q,Q,E+S,S, Q,E+S,S,H};
unsigned int TOTAL = 18;

// ---------------------------------------------------------------------------------

void setup(void)
{
  pinMode(VCC,OUTPUT);
  digitalWrite(VCC, HIGH);
  
  pinMode(GND,OUTPUT);
  digitalWrite(GND, LOW);
  
  pinMode(SPK,OUTPUT);
  digitalWrite(SPK, LOW);
  
  pinMode(RED,OUTPUT);
  digitalWrite(RED, LOW);
}

void loop(void)
{
  static int i = 0;
  tone(SPK, note[i], duration[i]);
  delay(1+duration[i]);

  i++;
  if (i >= TOTAL) i = 0;
  
  analogWrite(RED, duration[i] / 4);
}
