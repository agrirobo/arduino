#define STOP_PIN 3
#define LOW_PIN 9
#define TURBO_PIN 10
#define STEP 200

int LowPower(){
  digitalWrite(LOW_PIN, HIGH);
  delay(STEP);
  digitalWrite(LOW_PIN, LOW);
  delay(STEP);
}

int Turbo(){
  digitalWrite(TURBO_PIN, HIGH);
  delay(STEP);
  digitalWrite(TURBO_PIN, LOW);
  delay(STEP);
}

void Stop(){
  digitalWrite(STOP_PIN, HIGH);
  delay(STEP);
  digitalWrite(STOP_PIN, LOW);
  delay(STEP);
}

void setup(){
  pinMode(STOP_PIN,  OUTPUT);
  pinMode(LOW_PIN,   OUTPUT);
  pinMode(TURBO_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop(){
  char i;

  if(Serial.available()){
    i = Serial.read();
    switch(i){
    case 0: Stop(); break;
    case 1: LowPower(); break;
    case 2: Turbo(); break;
    }
  }
}
