/*
* LAB Name: ESP32->ESP32 Bluetooth Communication (MASTER CODE)
*   [ MASTER CODE ]
* Author: Khaled Magdy
* DeepBlueMbedded 2023
* For More Info Visit: www.DeepBlueMbedded.com
*/
#include "String.h"
#include "CRC16.h"
#include "CRC.h"
#include "stdio.h"
#include "HardwareSerial.h"
#include "BluetoothSerial.h"
#include <stdlib.h>


 
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

String nrechip = "AT+U322";
String primesc;
String lastThree{};
int cuc;
int sum;
char str[4];
char str1[10];
char result[20];
String finalrez;

BluetoothSerial SerialBT;
String slaveName = "PHNT3"; // Change this to reflect the real name of your slave BT device
uint8_t address[6]  = {0x58, 0xBF, 0x25, 0x93, 0x29, 0x4E}; 
String myName = "ESP32-BT-Master";
void setup() {
  bool connected;
  Serial.begin(115200);
  SerialBT.begin(myName, true);
  Serial.printf("The device \"%s\" started in master mode, make sure slave BT device is on!\n", myName.c_str());
  // connect(address) is fast (up to 10 secs max), connect(slaveName) is slow (up to 30 secs max) as it needs
  // to resolve slaveName to address first, but it allows to connect to different devices with the same name.
  // Set CoreDebugLevel to Info to view devices Bluetooth address and device names
  connected = SerialBT.connect(slaveName);
  Serial.printf("Connecting to slave BT device named \"%s\"\n", slaveName.c_str());
  if(connected) {
    Serial.println("Connected Successfully!");
        String command = "AT+U303";
    SerialBT.println(command);
    String data=SerialBT.readString();
    Serial.println(data);
    data=data.substring(data.length() - 4);
    sum= atoi(data.c_str())+555+303;
    data=String(sum);
    char buffer[5];
    data.toCharArray(buffer, 5);

    

    char str[24] =  "1578";
    char str1[24]; 
 
   










  Serial.println(buffer);
    String rez=String(crc16((uint8_t *) buffer, 4, 0x1021, 0, 0, false, false), DEC);
    String rezultatFinal=String(data+rez);
    SerialBT.println(rezultatFinal);
    
    Serial.println(rezultatFinal);
    String a;
    a=SerialBT.readString();
    Serial.println(a);
    a=SerialBT.readString();
     Serial.println(a);
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
    } 
  }
  // Disconnect() may take up to 10 secs max
  if (SerialBT.disconnect()) {
    Serial.println("Disconnected Successfully!");
  }
  // This would reconnect to the slaveName(will use address, if resolved) or address used with connect(slaveName/address).
  SerialBT.connect();
  if(connected) {
    Serial.println("Reconnected Successfully!");
  } else {
    while(!SerialBT.connected(10000)) {
      Serial.println("Failed to reconnect. Make sure remote device is available and in range, then restart app.");
    }
  }
}
void loop() {

    //String data = SerialBT.readString(); // read until new line character
    //Serial.println("Received data: " + data);
 
 delay(1000);
}
