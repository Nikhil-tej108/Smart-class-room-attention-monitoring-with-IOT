#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDR_PIN 34
#define LED 2

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void reconnect() {
  if (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println(" Connected");
    } else {
      Serial.println(" Failed");
    }
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int light = analogRead(LDR_PIN);

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" | Hum: "); Serial.print(hum);
  Serial.print(" | Light: "); Serial.println(light);

  if (light < 1500) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);

  String payload = "{";
  payload += "\"temp\":" + String(temp) + ",";
  payload += "\"humidity\":" + String(hum) + ",";
  payload += "\"light\":" + String(light);
  payload += "}";

  client.publish("classroom/data", payload.c_str());

  delay(3000);
}