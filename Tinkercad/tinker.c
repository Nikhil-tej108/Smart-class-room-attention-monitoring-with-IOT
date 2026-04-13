int sensorPin = A0;

int greenLED = 7;
int yellowLED = 6;
int redLED = 5;
int buzzer = 8;

int value = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  value = analogRead(sensorPin);

  int percentage = map(value, 0, 1023, 0, 100);

  Serial.print("Noise Value: ");
  Serial.print(value);
  Serial.print(" | Noise %: ");
  Serial.println(percentage);

  // Reset all outputs
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);

  if (percentage < 30) {
    digitalWrite(greenLED, HIGH);
  }
  else if (percentage < 70) {
    digitalWrite(yellowLED, HIGH);
  }
  else {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 2000);
  }

  delay(200);
}