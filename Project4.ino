#include <WiFi.h>
#include <PubSubClient.h>
const char* ssid = ":D";
const char* password = "13october";
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const char* mqtt_server = "broker.mqtt-dashboard.com";
const int mqtt_port = 1883;
const char* mqtt_Client = "esp32-555";
const char* mqtt_username = "pi12345678";
const char* mqtt_password = "pi12345678";
WiFiClient espClient;
PubSubClient client(espClient);
char msg[150];
#define R1 15
#define R2 4
#define R3 16
#define R4 17
const int WaterLevel1 = 13;
const int WaterLevel2 = 12;

const int WaterLevel4 = 27;

const int WaterLevel6 = 23; 


long lastMsg = 0;
int value = 0;
int WL1 = 0;
int WL2 = 0;

int WL4 = 0;

int WL6 = 0;


//ec sersor
#include <OneWire.h>
#define StartConvert 0
#define ReadTemperature 1
const byte numReadings = 20; //the number of sample times
byte ECsensorPin = 35; //EC Meter analog output,pin on analog 0
byte DS18B20_Pin = 2; //DS18B20 signal, pin on digital 2
unsigned int AnalogSampleInterval=25,printInterval=1000,tempSampleInterval=850; //analog sample interval;serial print interval;temperature sample interval
unsigned int readings[numReadings]; // the readings from the analog input
byte ec55 = 0; // the ec55 of the current reading
unsigned long AnalogValueTotal = 0; // the running total
unsigned int AnalogAverage = 0,averageVoltage=0; // the average
unsigned long AnalogSampleTime,printTime,tempSampleTime;
float temperature,ECcurrent,TempCoefficient,CoefficientVolatge;
//Temperature chip i/o
OneWire ds(DS18B20_Pin); // on digital pin 2
