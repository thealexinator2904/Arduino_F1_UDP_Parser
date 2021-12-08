#include <Arduino.h>

#include "WiFi.h" // ESP32 WiFi include
#include <WiFiUdp.h>
#include <F_UDP_Parser.h>

const char *SSID = "Your SSID";
const char *WiFiPassword = "YOur PW";

void ConnectToWiFi();
 
//The IP address that this arduino has requested to be assigned to.
IPAddress ip();
WiFiUDP Udp;
int flag = 0;

unsigned int localPort = 8888; 

F1_UDP_Parser* parser;

void setup() 
{ 
  parser = new F1_UDP_Parser();
  Serial.begin(115200);
  ConnectToWiFi();
  Udp.begin(localPort);
}

void loop()
{
  int packetSize = Udp.parsePacket(); 
    if(packetSize) 
    {
       char packetBuffer[packetSize];
       while(Udp.available())
       {
        Udp.read(packetBuffer, packetSize);
       }
       parser->push(packetBuffer);
       Serial.print("Speed: ");
       Serial.println(parser->packetCarTelemetryData()->m_carTelemetryData(0).m_speed);
  }
}
void ConnectToWiFi()
{
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, WiFiPassword);
  Serial.print("Connecting to "); Serial.println(SSID);
 
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);
 
    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }
 
  Serial.print(F("Connected. My IP address is: "));
  Serial.println(WiFi.localIP());
}
