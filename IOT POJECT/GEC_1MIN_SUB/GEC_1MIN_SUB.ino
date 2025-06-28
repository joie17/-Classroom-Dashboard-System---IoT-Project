#include <WiFi.h>

// Replace with your WiFi credentials
const char* ssid = "OnePlus Nord CE 2 Jainil";     // 🔹 Change this
const char* password = "JKD@1711"; // 🔹 Change this

void setup() {
  Serial.begin(115200);  // Start serial monitor

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print the assigned IP
}

void loop() {
  // Do nothing, just keep WiFi running
}
