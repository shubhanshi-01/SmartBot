#include <ESP8266WiFi.h>   // For ESP8266
// #include <WiFi.h>        // For ESP32
#include <WiFiUdp.h>
const char* ssid = "vivo V25";
const char* password = "9861462572";
WiFiUDP udp;
unsigned int localPort = 4440;  
void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  udp.begin(localPort);
  Serial.println("UDP server started");
  
}
int c=0;
void loop() {
  
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char packetBuffer[255]; 
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    char tempValue[4];
    //Serial.println(packetBuffer);
    memcpy(tempValue, &packetBuffer[18], 3); 
    tempValue[3] = '\0';
    int value18 = atoi(tempValue);
    c+=1;
    if(c==1)
    {
      Serial.println('a');
    }
    Serial.println(value18);
  }
  delay(10);
}



