#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

// Define MAX7219 connections
#define MAX_DEVICES 4  
#define DATA_PIN 23    
#define CLK_PIN 18     
#define CS_PIN 5      

MD_Parola matrix = MD_Parola(MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  Serial.begin(115200);
  matrix.begin();
  matrix.setIntensity(5);
  matrix.displayClear();
}

void loop() {
  matrix.displayText("HELLO", PA_CENTER, 100, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);

  if (matrix.displayAnimate()) {
    matrix.displayReset();
  }
}
