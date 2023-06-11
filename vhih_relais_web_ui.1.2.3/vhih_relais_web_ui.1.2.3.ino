
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include <AsyncElegantOTA.h>
#include <elegantWebpage.h>
#include "virtualHomee.hpp"
#include <ESPAsyncUDP.h>
#include "LittleFS.h"
#include "index_html.h"

unsigned long relay1Milli = 0;
unsigned long relay2Milli = 0;
unsigned long relay3Milli = 0;
unsigned long relay4Milli = 0;
unsigned long lastMillis = 0;
unsigned long last2Millis = 0;
unsigned long last3Millis = 0;
unsigned long last4Millis = 0;
unsigned long lasttestMillis = 0;

unsigned long currentMillis = millis();

virtualHomee vhih;

nodeAttributes* na1;
nodeAttributes* na2;  //config
nodeAttributes* na3; // Zeitablauf
nodeAttributes* na4;
nodeAttributes* na5;

nodeAttributes* na1_2;
nodeAttributes* na2_2;
nodeAttributes* na3_2; // Zeitablauf

nodeAttributes* na1_3;
nodeAttributes* na2_3;
nodeAttributes* na3_3; // Zeitablauf

nodeAttributes* na1_4;
nodeAttributes* na2_4;
nodeAttributes* na3_4; // Zeitablauf

nodeAttributes* na40_5; // Taster 1
nodeAttributes* na41_5; // Taster 1

nodeAttributes* na40_6; // Taster 2
nodeAttributes* na41_6; // Taster 2

nodeAttributes* na40_7; // Taster 3
nodeAttributes* na41_7; // Taster 3

nodeAttributes* na40_8; // Taster 4
nodeAttributes* na41_8; // Taster 4

const int relay = 16;//13
const int relay2 = 14;//12
const int relay3 = 12;//14
const int relay4 = 13;//16

const int switch_1 = 5;//5
const int switch_2 = 4;
const int switch_3 = 0;
const int switch_4 = 2;

int switch_1_state = 0;
int switch_2_state = 0;
int switch_3_state = 0;
int switch_4_state = 0;

int na2_value = 60;

int na2_2_value = 60;
int na2_3_value = 60;
int na2_4_value = 60000;

int na41_5_value = 0;
int na41_6_value = 0;
int na41_7_value = 0;
int na41_8_value = 0;

int last_rssi = 0;
int rssi = 0 ;
AsyncWebServer server(80);

const char* PARAM_INPUT_1 = "ssid";
const char* PARAM_INPUT_2 = "pass";

bool vhih_state = false ; 

String ssid;
String pass;

const char* ssidPath = "/ssid.txt";
const char* passPath = "/pass.txt";


IPAddress localIP;
IPAddress localGateway;
IPAddress subnet(255, 255, 0, 0);


unsigned long previousMillis = 0;
unsigned long lastMillis3 = 0;
const long interval = 10000;
boolean restart = false;


bool initWiFi() {
  WiFi.begin(ssid.c_str(), pass.c_str());
  Serial.println("Connecting to WiFi...");
  delay(1000);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect.");
    return false;
  }
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.RSSI());
  Serial.println(WiFi.macAddress());
  Serial.println((char*)WiFi.getHostname());
  return true;
}
String readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return String();
  }
  String fileContent;
  while (file.available()) {
    fileContent = file.readStringUntil('\n');
    break;
  }
  file.close();
  return fileContent;
}
void setup() {
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(switch_1, INPUT_PULLUP);
  pinMode(switch_2, INPUT_PULLUP);
  pinMode(switch_3, INPUT_PULLUP);
  pinMode(switch_4, INPUT_PULLUP);
  Serial.begin(115200);
  initFS();
  ssid = readFile(LittleFS, ssidPath);
  pass = readFile(LittleFS, passPath);
  Serial.println(ssid);
  AsyncElegantOTA.begin(&server);  // Start AsyncElegantOTA
  
  if (initWiFi()) {
    http_GET();
    server.begin();
     vhih.start();
     vhih_state = true;
  }
  else {
    Serial.println("Setting AP (Access Point)");
    WiFi.softAP("vhih ESP WLAN", NULL);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
    http_GET();
    server.begin();
  }
  device();
 
}
void rssif() {

  if (-WiFi.RSSI() > 90 ) {
    rssi = 0;
  }
  else if (-WiFi.RSSI() > 80 && -WiFi.RSSI() < 90 ) {
    rssi = 1;
  }
  else if (-WiFi.RSSI() > 55 && -WiFi.RSSI() < 75 ) {
    rssi = 2;
  }
  else if (-WiFi.RSSI() > 35 && -WiFi.RSSI() < 55 ) {
    rssi = 3;
  }
  else if (-WiFi.RSSI() > 0 && -WiFi.RSSI() < 35 ) {
    rssi = 4;
  }
  if ( rssi != last_rssi) {
    na5->setCurrentValue(rssi);
    vhih.updateAttribute(na5);
    last_rssi = rssi;
  }
}


void loop() {
  if (restart) {
    delay(2000);
    ESP.restart();
  }
  currentMillis = millis();
  if ( currentMillis - lastMillis3 >= 30000){
    lastMillis3 = currentMillis;
    if (WiFi.status() != WL_CONNECTED){
      vhih_state = false;
      WiFi.begin(ssid.c_str(), pass.c_str());
      WiFi.softAP("vhih ESP WLAN", NULL);
    }
    if (WiFi.status() == WL_CONNECTED && vhih_state == false){
      
      vhih.start();
      vhih_state = true;
      WiFi.softAPdisconnect();
    }
    
  }
  switching_off();
  toggle();
  rssif();
  delay(50);
}

void http_GET() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest * request) {
    String inputMessage;
    if (request->hasParam(PARAM_SSID)) {
      inputMessage = request->getParam(PARAM_SSID)->value();
      writeFile(LittleFS, ssidPath, inputMessage.c_str());
    }
    else if (request->hasParam(PARAM_PASSWORT)) {
      inputMessage = request->getParam(PARAM_PASSWORT)->value();
      writeFile(LittleFS, passPath, inputMessage.c_str());
    }
    else if (request->hasParam(PARAM_reset)) {
      inputMessage = request->getParam(PARAM_reset)->value();
      restart = true;
    }

  else if (request->hasParam(PARAM_relay1)) {
  inputMessage = request->getParam(PARAM_relay1)->value();
    if (inputMessage == "true" && digitalRead(relay) == LOW) {
      digitalWrite(relay, HIGH);
      na1->setCurrentValue(1);
      na1->setTargetValue(1);
      vhih.updateAttribute(na1);
      na3->setTargetValue(60);
      vhih.updateAttribute(na3);
      relay1Milli = currentMillis;
    }
    else if (inputMessage == "true" && digitalRead(relay) == HIGH) {
      digitalWrite(relay, LOW);
      na1->setCurrentValue(0);
      na1->setTargetValue(0);
      vhih.updateAttribute(na1);
      na3->setCurrentValue(0);
      vhih.updateAttribute(na3);
      relay1Milli = currentMillis;
    }
  }
  else if (request->hasParam(PARAM_relay2)) {
  inputMessage = request->getParam(PARAM_relay2)->value();
    if (inputMessage == "true" && digitalRead(relay2) == LOW) {
      digitalWrite(relay2, HIGH);
      na1_2->setCurrentValue(1);
      na1_2->setTargetValue(1);
      vhih.updateAttribute(na1_2);
      na3_2->setTargetValue(60);
      vhih.updateAttribute(na3_2);
      relay2Milli = currentMillis;
    }
    else if (inputMessage == "true" && digitalRead(relay2) == HIGH) {
      digitalWrite(relay2, LOW);
      na1_2->setCurrentValue(0);
      na1_2->setTargetValue(0);
      vhih.updateAttribute(na1_2);
      na3_2->setCurrentValue(0);
      vhih.updateAttribute(na3_2);
      relay2Milli = currentMillis;
    }
  }
  
  else if (request->hasParam(PARAM_relay3)) {
  inputMessage = request->getParam(PARAM_relay3)->value();
    Serial.println(inputMessage);
    if (inputMessage == "true" && digitalRead(relay3) == LOW) {
      digitalWrite(relay3, HIGH);
      na1_3->setCurrentValue(1);
      na1_3->setTargetValue(1);
      vhih.updateAttribute(na1_3);
      na3_3->setTargetValue(60);
      vhih.updateAttribute(na3_3);
      relay3Milli = currentMillis;
    }
    else if (inputMessage == "true" && digitalRead(relay3) == HIGH) {
      digitalWrite(relay3, LOW);
      na1_3->setCurrentValue(0);
      na1_3->setTargetValue(0);
      vhih.updateAttribute(na1_3);
      na3_3->setCurrentValue(0);
      vhih.updateAttribute(na3_3);
      relay3Milli = currentMillis;
    }
  }
  else if (request->hasParam(PARAM_relay4)) {
  inputMessage = request->getParam(PARAM_relay4)->value();
    if (inputMessage == "true" && digitalRead(relay4) == LOW) {
      digitalWrite(relay4, HIGH);
      na1_4->setCurrentValue(1);
      na1_4->setTargetValue(1);
      vhih.updateAttribute(na1_4);
      na3_4->setTargetValue(60);
      vhih.updateAttribute(na3_4);
      relay4Milli = currentMillis;
    }
    else if (inputMessage == "true" && digitalRead(relay4) == HIGH) {
      digitalWrite(relay4, LOW);
      na1_4->setCurrentValue(0);
      na1_4->setTargetValue(0);
      vhih.updateAttribute(na1_4);
      na3_4->setCurrentValue(0);
      vhih.updateAttribute(na3_4);
      relay4Milli = currentMillis;
    }
  }
  else {
    inputMessage = "No message sent";
  }
  request->send_P(200, "text/html", index_html, processor);
});
}

String processor(const String& var) {
  if (var == "inputSsid") {
    return ssid;
  }
  else if (var == "relay1") {
    if (digitalRead(relay) == HIGH) {
      return "green";
    }
    else
    { return "red";

    }
  }
  else if (var == "relay2") {
    if (digitalRead(relay2) == HIGH) {
      return "green";
    }
    else
    { return "red";

    }
  }
  else if (var == "relay3") {
    if (digitalRead(relay3) == HIGH) {
      return "green";
    }
    else
    { return "red";

    }
  }
  else if (var == "relay4") {
    if (digitalRead(relay4) == HIGH) {
      return "green";
    }
    else
    { return "red";

    }
  }

  return String();
}

void testt() {
  if ( currentMillis - lasttestMillis >= 10000) {
    lasttestMillis = currentMillis;
    Serial.println( digitalRead(switch_1));
    Serial.println( digitalRead(switch_2));
    Serial.println( digitalRead(switch_3));
    Serial.println( digitalRead(switch_4));
  }

}
