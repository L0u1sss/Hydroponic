void reconnect() {
while (!client.connected()) 
{
Serial.print("Attempting MQTT connection...");
if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) 
    {
    lcd.setCursor(0, 1);
    lcd.print("MQTT Connected");
    Serial.println("connected");
    client.subscribe("msg/pump_1");
    client.subscribe("msg/pump_2");
    client.subscribe("msg/pump_3");
    client.subscribe("msg/emer/hydro");
    }
    else 
  {
  lcd.setCursor(0, 1);
  lcd.print("  Reconnection  ");
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println("try again in 5 seconds");
  delay(5000);
  }
}
}
