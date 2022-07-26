const int trigPinRight = 8;
const int echoPinRight = 5;
const int trigPinLeft = 8;
const int echoPinLeft = 6;
const int trigPinFront = 8;
const int echoPinFront = 7;
const int ledPin = 13;
const int buzzerPin = 10;
const int vibratorPin = 9;

void setup()
{
  Serial.begin (9600);
  pinMode(trigPinRight, OUTPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinRight, INPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(vibratorPin, OUTPUT);
}
void loop()
{
  long durationRight, cmRight;
  long durationLeft, cmLeft;
  long durationfront, cmfront;
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  cmRight = (durationRight / 2) / 29.1;
  if (cmRight <= 400)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(vibratorPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(vibratorPin, LOW);
    digitalWrite(buzzerPin, LOW);

  }
  if (cmRight > 400)
  {
    Serial.println("out of range");
    noTone(buzzerPin);
  }
  else
  {
    Serial.print(cmRight);
    Serial.print("cm - Right side");
    Serial.println();
    tone(buzzerPin, HIGH);
    delay(800);
  }
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  cmLeft = (durationLeft / 2) / 29.1;
  if (cmLeft <= 400)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(vibratorPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(vibratorPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  if (cmLeft > 400)
  {
    Serial.println("out of range");
    noTone(buzzerPin);
  }
  else
  {
    Serial.print(cmLeft);
    Serial.print("cm - Left side");
    Serial.println();
    tone(buzzerPin, HIGH);
    delay(800);
  }
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationfront = pulseIn(echoPinFront, HIGH);
  cmfront = (durationfront / 2) / 29.1;
  if (cmfront <= 400)
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(vibratorPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

  }
  else
  {
    digitalWrite(ledPin, LOW);
    digitalWrite(vibratorPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  if (cmfront > 400)
  {
    Serial.println("out of range");
    noTone(buzzerPin);
  }
  else
  {
    Serial.print(cmfront);
    Serial.print("cm-front side");
    Serial.println();
    tone(buzzerPin, HIGH);
  }
  delay(800); //ms
}
