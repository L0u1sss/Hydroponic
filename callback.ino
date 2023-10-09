void callback(char* topic, byte* payload, unsigned int length) {
//Serial.print("Message arrived [");
//Serial.print(topic);
//Serial.print("] ");

String message;
for (int i = 0; i < length; i++) {
 message = message + (char)payload[i];
}

//double getValue = message.toDouble();
float getValueFloat = message.toFloat();
//int getVauleInt = message.toInt();
Serial.println("////original/////");
Serial.println(message);
Serial.println("/////float////");
//Serial.println(getValue);
Serial.println(getValueFloat);
//Serial.println(getVauleInt);
    if ((String(topic) == "msg/pump_1")) {
      if ((getValueFloat == 0.00)&&(WL2 != 0)){
        digitalWrite(R1, 0);
        Serial.println("R1 ON");
        client.publish("msg/pump_1/status", "1");
        }
      else if (getValueFloat == 1.00) {
      digitalWrite(R1, 1);
      Serial.println("R1 OFF");
      client.publish("msg/pump_1/status", "0");
        }
    }
    
    if (String(topic) == "msg/pump_2") {
      Serial.println("////compare////");
      Serial.println(getValueFloat);
      Serial.println(ECcurrent);
      if ((getValueFloat < ECcurrent)&&(WL2 != 0)&&(WL4 != 0)&&(WL6 != 0)) //maxน้อยกว่าวัดได้ เติมน้ำ
        {
        digitalWrite(R2, 0);
        Serial.println("R2 ON");
        client.publish("msg/pump_2/status", "1");
        }
      else if (getValueFloat > ECcurrent) //maxมากกว่าวัดได้ หยุดน้ำ
        {
        digitalWrite(R2, 1);
        Serial.println("R2 OFF");
        client.publish("msg/pump_2/status", "0");
        }
    }
    if (String(topic) == "msg/pump_3") {
      Serial.println("////compare////");
      Serial.println(getValueFloat);
      Serial.println(ECcurrent);
      if ((getValueFloat > ECcurrent)&&(WL2 != 0)&&(WL4 != 0)&&(WL6 != 0)) //minมากกว่าวัดได้ เติมปุ๋ย
        {
        digitalWrite(R3, 0);
        digitalWrite(R4, 0);
        Serial.println("R3 ON");
        client.publish("msg/pump_34/status", "1");
        }
      else if (getValueFloat < ECcurrent) //minน้อยกว่าวัดได้ หยุดปุ๋ย
        {
        digitalWrite(R3, 1);
        digitalWrite(R4, 1);
        Serial.println("R3 OFF");
        client.publish("msg/pump_34/status", "0");
        }
    }
}
