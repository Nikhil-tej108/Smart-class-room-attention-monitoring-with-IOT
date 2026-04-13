#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SENSOR_PIN 26  // GP26

// TinyML Function
String predictAttention(int noise, int light, int movement) {
  int score = (light * 0.4) + ((100 - noise) * 0.4) + ((100 - movement) * 0.2);

  if (score > 70) return "Focused";
  else if (score > 40) return "Moderate";
  else return "Distracted";
}

void setup() {
  Serial.begin(115200);

  // IMPORTANT: correct I2C pins
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.clearDisplay();

  // TEST MESSAGE (to confirm OLED works)
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.println("START");
  display.display();

  delay(2000);
}

void loop() {
  int raw = analogRead(SENSOR_PIN);
  int noise = map(raw, 0, 1023, 0, 100);

  int light = random(40, 100);
  int movement = random(10, 80);

  String result = predictAttention(noise, light, movement);

  // Clear screen
  display.clearDisplay();

  // Print data (simple layout)
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Noise: ");
  display.println(noise);

  display.print("Light: ");
  display.println(light);

  display.print("Move: ");
  display.println(movement);

  display.setCursor(0, 40);
  display.print("Status:");

  display.setCursor(0, 50);
  display.print(result);

  // VERY IMPORTANT
  display.display();

  Serial.println(result);

  delay(1000);
}