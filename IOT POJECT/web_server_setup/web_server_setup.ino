#include <WiFi.h>
#include <WebServer.h>

// 🔹 Replace with your WiFi credentials
const char* ssid = "OnePlus Nord CE 2 Jainil";     
const char* password = "JKD@1711";

// Create a web server on port 80
WebServer server(80);

// 🔹 Webpage content
const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Web Server</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; }
    h1 { color: #3498db; }
    button { font-size: 20px; padding: 10px; margin: 10px; cursor: pointer; }
  </style>
</head>
<body>
  <h1>Welcome to ESP32 Web Server</h1>
  <p>Click the button below to refresh the page.</p>
  <button onclick="window.location.reload();">Refresh</button>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Define the main page route
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", MAIN_page);
  });

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}
