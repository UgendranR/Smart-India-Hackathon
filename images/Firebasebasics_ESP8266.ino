#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

const char* FIREBASE_HOST = "iot-with-8266-prem.firebaseio.com";
const char* FIREBASE_AUTH = "rKwCtQ0Vq1IB3P2cGwcrlTeG22wFZCDJujvng5VW";
const char* ssid = "OnePlus 6T P"; //Enter SSID
const char* password = "........"; //Enter Password

String firestatus = "";

//int led=2;
void setup(void)
{
  Serial.begin(9600);
  // Connect to WiFi

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);

    Serial.print("*");
  }

  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address


  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("led", "OFF");


}

void loop()
{
  firestatus = Firebase.getString("led");
  if (firestatus == "ON")
  {
    Serial.println("LED ON");
    digitalWrite(2, HIGH);
  }
  else if (firestatus == "OFF")
  {
    Serial.println("LED OFF");
    digitalWrite(2, LOW);
  }
  else
    Serial.println("Data recieved is not ON or OFF");
}
