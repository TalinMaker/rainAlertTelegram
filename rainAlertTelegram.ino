#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Telegram bot token and chat ID
String botToken = "YOUR_BOT_TOKEN";
String chatID = "YOUR_CHAT_ID";

// Pin for the rain sensor
const int rainSensorPin = 14;  // Use an appropriate GPIO pin for your ESP32

void setup() {
  // Configure rain sensor pin
  pinMode(rainSensorPin, INPUT);

  // Start serial and Wi-Fi connection
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi!");
}

void loop() {
  // Read rain sensor
  int rainValue = digitalRead(rainSensorPin);
  
  // Check if rain is detected
  if (rainValue == LOW) {  // Adjust to HIGH if your sensor logic is reversed
    Serial.println("Rain detected!");
    sendMessage("Alert! Rain detected.");
    
    // Wait before sending another message
    delay(60000);  // 1 minute delay to avoid flooding messages
  }

  delay(500);  // Short delay for sensor stability
}

// Function to send message via Telegram
void sendMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=" + message;

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("Message sent successfully.");
    } else {
      Serial.print("Error sending message: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Not connected to Wi-Fi");
  }
}
