#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
//#define FIREBASE_HOST "medidor-26011.firebaseio.com"
//#define FIREBASE_HOST "conexion-c2717.firebaseio.com"
//#define FIREBASE_AUTH "U0v0OJPQn37JEIyCUoxe0QqW94PjegrE6I0iutR8" //
#define FIREBASE_HOST "micasa-95e3c.firebaseio.com"
#define FIREBASE_AUTH "mpxUOlTMNKP4vw0dDgtECnPSpSjb6xa22dl3aL1q"
#define WIFI_SSID "ROMERO"                                       //modificar credenciales
#define WIFI_PASSWORD "romero2016"

//FirebaseArduino FirebaseStream;

int led = 16;
int led2 = 5;
String msj1 = "Conectado";
String msj2 = "uno";
String msj3 = "dos";
int uno = 1;
int cero = 0;



void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // connect to wifi.
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.stream("/scores/latest/score/score");
  if (Firebase.failed()) {
    Serial.println("error conexion");
    Serial.println(Firebase.error());
  }
  Firebase.setString("mensaje", msj1);
  digitalWrite(led, HIGH);
  delay(1000);
  if (Firebase.failed()) {
    Serial.println("streaming error");
    Serial.println(Firebase.error());
  }
  
}

void loop()
{
  Firebase.setInt("rele1", uno);
  digitalWrite(led2, HIGH);
  if (Firebase.failed()) {
    Serial.println("error streaming");
    Serial.println(Firebase.error());
  }
  
  delay(500);
  Firebase.setInt("rele1", cero);
  digitalWrite(led2, LOW);
  delay(500);
  if (Firebase.failed()) {
    Serial.println("error streaming");
    Serial.println(Firebase.error());
  }
  
}

