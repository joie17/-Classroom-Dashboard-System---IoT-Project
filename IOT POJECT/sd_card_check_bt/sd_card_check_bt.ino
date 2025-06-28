#include "BluetoothSerial.h"

BluetoothSerial SerialBT; // Create Bluetooth object

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Timetable"); // Set Bluetooth name
  Serial.println("✅ Bluetooth Started. Waiting for connection...");
}

void loop() {
  if (SerialBT.available()) {
    String receivedData = SerialBT.readString(); // Read data from Bluetooth
    Serial.print("📩 Received: ");
    Serial.println(receivedData);
  }
}
