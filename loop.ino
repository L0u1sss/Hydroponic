void loop() {
if (!client.connected()) 
{
reconnect();
}
client.loop();

  static unsigned long Time = millis();
  if((millis()-Time)>5000){
  Time = millis();
ec();  
String data = String(ECcurrent);
//  Serial.println(data);
  data.toCharArray(msg, (data.length() + 1));
  client.publish("msg/ec", msg);
  
WL1 = digitalRead(WaterLevel1);
WL2 = digitalRead(WaterLevel2);

WL4 = digitalRead(WaterLevel4);

WL6 = digitalRead(WaterLevel6);

// Serial.print("wl1 = ");
// Serial.println(WL1);
// Serial.print("wl2 = ");
// Serial.println(WL2);
//
// Serial.print("wl4 = ");
// Serial.println(WL4);
//
// Serial.print("wl6 = ");
// Serial.println(WL6);

 Serial.print(ECcurrent,2); //two decimal
Serial.println("ms/cm");
Serial.println("");
  
if (WL1 == HIGH){
  client.publish("msg/tank1", "0");
  }
if (WL1 == LOW){
  client.publish("msg/tank1", "1");
  }
if (WL2 == HIGH){
  client.publish("msg/tank2", "0");
  }
if (WL2 == LOW){
  client.publish("msg/tank2", "1");
  }
if (WL4 == HIGH){
  client.publish("msg/tank3", "0");
  }
if (WL4 == LOW){
  client.publish("msg/tank3", "1");
  }
if (WL6 == HIGH){
  client.publish("msg/tank4", "0");
  }
if (WL6 == LOW){
  client.publish("msg/tank4", "1");
  }
  }
}
