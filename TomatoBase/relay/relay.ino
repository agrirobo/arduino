#define STOP_PIN 3
#define LOW_PIN 9
#define TURBO_PIN 10

int LowPower();
int Turbo();
void Stop();

void switch_do(int);

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
    case 0: Stop(); break;
    case 1: LowPower(); break;
    case 2: Turbo(); break;
    }
  }
}

int LowPower()
{
  switch_do(LOW_PIN);
}

int Turbo()
{
  switch_do(TURBO_PIN);
}

void Stop()
{
  switch_do(STOP_PIN);
}

void switch_do(int pin_num)
{
  const int step = 200;
  digitalWrite(pin_num, HIGH);
  delay(step);
  digitalWrite(pin_num, LOW);
  delay(step);
}
