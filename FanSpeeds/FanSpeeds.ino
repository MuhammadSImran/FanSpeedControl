int Fan1 = 9;
int Fan2 = 10;
int Fan3 = 11;

void setup() 
{
  pinMode(Fan1, OUTPUT);
  pinMode(Fan2, OUTPUT);
  pinMode(Fan3, OUTPUT);

  Serial.begin(9600);

}

void loop() 
{
  if (Serial.available() >= 2 ) {

    unsigned int fanspeed = Serial.read();
    unsigned int fanspeed1 = Serial.read();
    unsigned int realFan = (fanspeed1 * 256) + fanspeed;
    Serial.println(realFan);

    if (realFan >= 1000 && realFan < 1180) {
      int F1 = realFan;
      F1 = map(F1, 1000, 1180, 0, 180);
      digitalWrite(Fan1, F1);
      Serial.println("Fan 1 is ON");
    }
    if (realFan >= 2000 && realFan < 2180) {
      int F2 = realFan;
      F2 = map(F2, 2000, 2180, 0, 180);
      digitalWrite(Fan2, F2);
      Serial.println("Fan 2 is ON");

    }
    if (realFan >= 3000 && realFan < 3180) {
      int F3 = realFan;
      F3 = map(F3, 3000, 3180, 0, 180);
      digitalWrite(Fan3, F3);
      Serial.println("Fan 3 is ON");

    }
        if (realFan >= 30000 && realFan < 30180) {
      int F1 = realFan;
      F1 = map(F1, 30000, 30180, 0, 180);
      int F2 = realFan;
      F2 = map(F2, 30000, 30180, 0, 180);
      int F3 = realFan;
      F3 = map(F3, 30000, 30180, 0, 180);
      digitalWrite(Fan1, F1);
      digitalWrite(Fan2, F2);
      digitalWrite(Fan3, F3);
      Serial.println("Fan 1 is ON");
      Serial.println("Fan 2 is ON");
      Serial.println("Fan 3 is ON");

    }
  }
}

//Programmed by Muhammad Imran
