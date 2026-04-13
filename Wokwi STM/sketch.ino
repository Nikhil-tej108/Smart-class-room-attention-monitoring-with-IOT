#define GREEN  PA5
#define YELLOW PA6
#define RED    PA7

#define SENSOR_PIN PA0

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int value = analogRead(SENSOR_PIN);

  // FIXED HERE
  int percentage = (value * 100) / 1023;

  Serial.print("Raw Value: ");
  Serial.print(value);
  Serial.print(" | Score: ");
  Serial.println(percentage);

  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);

  if (percentage < 30) {
    digitalWrite(RED, HIGH);
  }
  else if (percentage < 70) {
    digitalWrite(YELLOW, HIGH);
  }
  else {
    digitalWrite(GREEN, HIGH);
  }

  delay(300);
}