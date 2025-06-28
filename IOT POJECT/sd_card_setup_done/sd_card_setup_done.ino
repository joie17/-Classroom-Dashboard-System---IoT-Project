#include <SPI.h>
#include <SD.h>

#define SD_CS 5 // Change to 5 if needed

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("🔄 Initializing SD card...");

  if (!SD.begin(SD_CS)) {
    Serial.println("❌ SD Card Initialization Failed! Check wiring.");
    return;
  }
  Serial.println("✅ SD Card Initialized!");

  // Open and read file
  File file = SD.open("/test.txt");
  if (file) {
    Serial.println("📖 Reading from test.txt:");
    while (file.available()) {
      Serial.write(file.read()); // Print file content
    }
    file.close();
    Serial.println("\n✅ File read successfully!");
  } else {
    Serial.println("❌ Failed to open test.txt!");
  }
}

void loop() {}
