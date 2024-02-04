#include "WiFiLogic.h"
#include <WiFi.h>
#include <WebServer.h>   

const char* ssid = "****"; //your WiFi Name
const char* password = "*****"; //your WiFi password 

WebServer server(8080);

WiFiLogic::WiFiLogic() {
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
}

void WiFiLogic::handleRoot() {
    String page = "<html><head><title>ESP32 Motor Control</title></head><body><h1>Motor Control</h1>";
  for (int i = 0; i < 4; i++) {
    page += "<p>Motor " + String(i+1) + ": <span id='power" + String(i) + "'>" + String(motorPower[i]) + "%</span> "
            "<button onclick='changePower(" + String(i) + ", 1)'>+</button> "
            "<button onclick='changePower(" + String(i) + ", -1)'>-</button></p>";
  }
  page += "<script>"
          "function changePower(motor, change) {"
          "  var xhttp = new XMLHttpRequest();"
          "  xhttp.onreadystatechange = function() {"
          "    if (this.readyState == 4 && this.status == 200) {"
          "      document.getElementById('power'+motor).innerHTML = this.responseText + '%';"
          "    }"
          "  };"
          "  xhttp.open('GET', 'set?motor='+motor+'&change='+change, true);"
          "  xhttp.send();"
          "}"
          "</script>"
          "</body></html>";
  server.send(200, "text/html", page);
}

void WiFiLogic::handleChangePower() {
    int motor = server.arg("motor").toInt();
  int change = server.arg("change").toInt();
  motorPower[motor] = constrain(motorPower[motor] + change, 0, 100);
  server.send(200, "text/plain", String(motorPower[motor]));

  CommunicationData data;
  data.timestamp = millis();
  data.action = "motors";
  
  data.value = String(motorPower[0]) + ":" + String(motorPower[1]) + ":" + String(motorPower[2]) + ":" + String(motorPower[3]);

  onDataReceived(data);
}

void WiFiLogic::init(DataReceivedCallback callback) {
    this->onDataReceived = callback;

    Serial.print("Connecting to ");
    Serial.println(ssid);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    WiFi.begin(ssid, password);
    WiFi.setTxPower(WIFI_POWER_18_5dBm);
    delay(600);
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    int last = LOW;
    int waiting = 0;
    while (WiFi.status() != WL_CONNECTED && waiting < 10000) {
        delay(600);
        digitalWrite(4, last);
        digitalWrite(2, !last);
        last = !last;
        Serial.print(".");
        waiting+=600;
    }
    delay(1000);
    wl_status_t status = WiFi.status();
    if (status != WL_CONNECTED) {
        Serial.println("Connection failed");
        if (status == WL_NO_SHIELD) {
            digitalWrite(4, LOW);
            digitalWrite(2, LOW);
            return;
        }
        last = LOW;
        for (int i=0; i<=1 + status; i++) {
            digitalWrite(4, last);
            digitalWrite(2, last);
            last = !last; 
            delay(1500);  
        }
        WiFi.disconnect();
        return;
    } else {
        for (int i=0; i<5; i++) {
            digitalWrite(4, last);
            digitalWrite(2, last);
            last = !last; 
            delay(500);  
        }    
    }
    delay(500);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    // Configuração do servidor web
    server.on("/", HTTP_GET, [this]() { this->handleRoot(); });
    server.on("/set", HTTP_GET, [this]() { this->handleChangePower(); });
    server.begin();
    Serial.println("HTTP server started");
}

void WiFiLogic::loop() {
    // TODO
    CommunicationData data;
    
    onDataReceived(data);
}
