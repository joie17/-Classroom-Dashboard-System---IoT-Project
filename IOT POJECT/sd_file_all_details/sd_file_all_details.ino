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

  // List all files on SD card
  Serial.println("📂 Files on SD card:");
  File root = SD.open("/");
  printDirectory(root, 0);
  root.close();

  // Try opening the file and reading it
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

void printDirectory(File dir, int numTabs) {
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) {
      break;
    }
    for (int i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
