#include <Arduino_JSON.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include<AntaresESP8266HTTP.h>
#include<ESP8266WIFI.h>
#include<Wire.h>

Servo myservo;
LiquidCrystal I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
int PinAnalogiqueHumidite = A0;
int PinNumeriqueHumidite = 2;
int etapsol = analogRead(A0);
int hmin;
int hmax;
int electrovanne = 13;
int servomoteur = 9;
const char* ssid = "globalnet/";
const char* password ="password";
String APIKEY = "cf56a077b8e92f14cee485a4e0f2b682";
String CityID = "253394";
WiFiClient client;
char servername[] ="api.openweathermap.org";
String result; 
String weatherDescription ="";
String weatherLocation ="";
String country;
int counter = 60;
int pluit;
float Temperature; 
float Humidity; 
float Pressure; 

if(counter==60){
    counter = 0;
    displayGettingData();
    delay(1000);
    getWeatherData();
  }
else {
    delay(5000);
    displayConditions(Temperature, Humidity, Pressure);
    delay(5000);
    counter ++ ;
    displayWeather(weatherDescription,weatherLocation);
  }
    
void getWeatherData(){
  if(client.connect(servername,80)){
    client.println("GET /data/2.5/weather?id="+CityID"&units=metric&APPID="+APIKEY);
    client.println("Host:api.openweathermap.org);
    client.println("User-Agent:ArduinoWiFi/1.1");
    client.println("Connection:close");
    client.println(); 
    
  }

else {
  Serial.println("connectionfailed"); 
  Serial.println();
  }
  
while(client.connected() && !client.available()){
  delay(1); 
  }

while(client.connected()||client.available()) { 
  char c = client.read(); 
  result = result+c; 
  }
  
client.stop(); 
result.replace('[', ' ');
result.replace(']', ' ');
Serial.println(result);
charjsonArray[result.length()+1];
result.toCharArray(jsonArray,sizeof(jsonArray);
jsonArray[result.length() + 1] = '\0';
StaticJsonBuffer<1024> 
json_buf;
JsonObject&root= json_buf.parseObject(jsonArray);
if (!root.success()){
  Serial.println("parseObject failed");
}
Stringlocation= root["name"];
Stringcountry=root["sys"] ["country"];
floattemperature=root["main"]["temp"];
floathumidity=root["main"]["humidity"];
Stringweather= root["weather"]["main"];
Stringdescription= root["weather"]["description"];
float pressure = root["main"]["pressure"];
weatherDescription = description;
weatherLocation = location;
Country = country;
Temperature = temperature;
Humidity = humidity;
Pressure = pressure;


voiddisplayWeather(String location,String description){
  lcd.clear();
  lcd.setCursor(0,0)
  lcd.print(location);
  lcd.print(", ");
  lcd.println(Country;
  lcd.println(description) ;
  delay(2000);
  
}

voiddisplayConditions(float Temperature,float Humidity, float Pressure) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp :");
  lcd.print(Temperature,1);
  lcd.print((char)223);
  lcd.println("C ");
  lcd.setCursor(0,1); 
  lcd.print("Humidity :");
  lcd.print(Humidity,0);
  lcd.println(" %");
  lcd.print("Pressure :");
  lcd.print(Pressure,1);
  lcd.println(" hPa");
  delay(5000);
}

void displayGettingData() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gettingdata");
  delay(1000);
  
}

void commande (){
  boolean vent ;
  if(weatherDescription="Windy") {
    Vent= 1 ;
    
  }
  else {
  vent = 0 ;
  }
  boolean pluie ;
  if (weatherDescription = "rainy") {
    pluie = 1 ;
  }
  else {
    pluie = 0 ;
    
  }


  int var=analogRead(A0) ;
  Serial.println(var);
  lcd.print(var);
  digitalWrite(electrovanne, HIGH);
  Serial.print(" EV OUVERTE ");
  digitalWrite(servomoteur, LOW);
  Serial.print(" protection ouverte ");
  delay(50);}
 if ((etapsol >= humin) && (pluie = 0)){
   if ((etapsol<=humax) && (pluie=1)){
     digitalWrite(electrovanne, LOW);
     Serial.print(" EV FERME ");
     digitalWrite(servomoteur, LOW);
     Serial.print(" protection ouverte ");
     delay(50); }
  if ((vent=1) && (pluie=1)) {
    digitalWrite(electrovanne, LOW);
    Serial.print(" EV FERME ");
    digitalWrite(servomoteur, LOW);
    Serial.print(" protection ouverte ");
    delay(50); }
  else{
    digitalWrite(electrovanne, LOW);
    Serial.print("EV FERME ");
    digitalWrite(servomoteur, HIGH);
    Serial.print(" protection FERME ");
    delay(50);
    
  }
   
 }



