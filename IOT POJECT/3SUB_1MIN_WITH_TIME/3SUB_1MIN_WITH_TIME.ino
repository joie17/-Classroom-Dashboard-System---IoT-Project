#include <Wire.h>
#include <RTClib.h>
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>
#include "BluetoothSerial.h"

// Define Bluetooth Serial
BluetoothSerial SerialBT;

// MAX7219 Configuration
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4  // Number of 8x8 matrices
#define DATA_PIN 23
#define CS_PIN   5
#define CLK_PIN  18

// Initialize MAX7219 display
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Initialize RTC
RTC_DS3231 rtc;

// Structure for lectures
struct Lecture {
  int startHour;
  int startMinute;
  char text[50];
};

// Default timetable
Lecture timetable[10]; // Store up to 10 lectures
int totalLectures = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Timetable"); // Bluetooth name

  Wire.begin();
  
  // Initialize MAX7219
  myDisplay.begin();
  myDisplay.setIntensity(5);
  myDisplay.displayClear();
  myDisplay.setTextAlignment(PA_CENTER);
  
  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  // Uncomment below line to set RTC time once
  // rtc.adjust(DateTime(2025, 2, 14, 10, 0, 0)); // YYYY, MM, DD, HH, MM, SS

  Serial.println("Waiting for Bluetooth timetable updates...");
}

void loop() {
  // Check for Bluetooth input
  if (SerialBT.available()) {
    char input[50];
    int bytesRead = SerialBT.readBytesUntil('\n', input, 50);
    input[bytesRead] = '\0'; // Null-terminate string
    
    Serial.println("Received: " + String(input));
    processBluetoothCommand(input);
  }

  // Get current time
  DateTime now = rtc.now();
  char timeString[6];
  sprintf(timeString, "%02d:%02d", now.hour(), now.minute());

  // Find the current lecture
  const char* currentLecture = "No Lecture";
  for (int i = 0; i < totalLectures; i++) {
    if (now.hour() == timetable[i].startHour && now.minute() >= timetable[i].startMinute && 
       (i == totalLectures - 1 || now.minute() < timetable[i + 1].startMinute)) {
      currentLecture = timetable[i].text;
      break;
    }
  }

  // Create scrolling text
  char displayText[100];
  sprintf(displayText, "%s, %s", timeString, currentLecture);

  // Scroll the text
  myDisplay.displayClear();
  myDisplay.displayText(displayText, PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  
  while (!myDisplay.displayAnimate()) {
    // Keep animating the text
  }

  delay(500);
}

// Process Bluetooth commands
void processBluetoothCommand(char* command) {
  int hour, minute;
  char text[50];

  // Example format: "10:05,GEC DAHOD, SEM 6, TOC, VIREN SIR"
  if (sscanf(command, "%d:%d,%49[^\n]", &hour, &minute, text) == 3) {
    if (totalLectures < 10) {
      timetable[totalLectures].startHour = hour;
      timetable[totalLectures].startMinute = minute;
      strcpy(timetable[totalLectures].text, text);
      totalLectures++;
      SerialBT.println("Lecture added!");
    } else {
      SerialBT.println("Lecture limit reached!");
    }
  } else {
    SerialBT.println("Invalid format! Use: HH:MM,Lecture Info");
  }
}
