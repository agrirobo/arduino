#define STOP_PIN  3
#define LOW_PIN   9
#define TURBO_PIN 10

void lowPower();
void turbo();
void stop();

void switchDo(int);

void setup()
{
  pinMode(STOP_PIN,  OUTPUT);
  pinMode(LOW_PIN,   OUTPUT);
  pinMode(TURBO_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    switch (ch)
    {
    case 0: stop(); break;
    case 1: lowPower(); break;
    case 2: turbo(); break;
    }
  }
}

void lowPower()
{
  switchDo(LOW_PIN);
}

void turbo()
{
  switchDo(TURBO_PIN);
}

void stop()
{
  switchDo(STOP_PIN);
}

void switchDo(int pin_num)
{
  const int step = 200;
  digitalWrite(pin_num, HIGH);
  delay(step);
  digitalWrite(pin_num, LOW);
  delay(step);
}
