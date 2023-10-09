void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
{
  delay(500);
  Serial.print(".");
}

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(WL1, INPUT);
  pinMode(WL2, INPUT);
  
  pinMode(WL4, INPUT);
  
  pinMode(WL6, INPUT);

  digitalWrite(R1, 1);
  digitalWrite(R2, 1);
  digitalWrite(R3, 1);
  digitalWrite(R4, 1);
  delay(500);
  digitalWrite(R1, 0);
  digitalWrite(R2, 0);
  digitalWrite(R3, 0);
  digitalWrite(R4, 0);
  delay(500);
  digitalWrite(R1, 1);
  digitalWrite(R2, 1);
  digitalWrite(R3, 1);
  digitalWrite(R4, 1);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IoT Control Box");
//ecsensor
  for(byte thisReading=0;thisReading<numReadings;thisReading++) readings[thisReading]=0;
  TempProcess(StartConvert); //let the DS18B20 start the convert
}
