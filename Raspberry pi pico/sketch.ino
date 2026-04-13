#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SENSOR_PIN 26  // GP26

void setup() {
  Serial.begin(115200);

  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  display.clearDisplay();
}

void loop() {
  int value = analogRead(SENSOR_PIN);
  int percentage = map(value, 0, 1023, 0, 100);

  String status;

  if (percentage < 30) status = "Distracted";
  else if (percentage < 70) status = "Moderate";
  else status = "Focused";

  // Display output
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 10);
  display.print("Attention:");

  display.setTextSize(2);
  display.setCursor(0, 25);
  display.print(percentage);
  display.print("%");

  display.setTextSize(1);
  display.setCursor(0, 50);
  display.print("Status: ");
  display.print(status);

  display.display();

  Serial.print("Score: ");
  Serial.println(percentage);

  delay(300);
}

