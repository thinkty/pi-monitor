#include <DHT.h>

#define BIT_PER_SEC 9600
#define DHT_TYPE    DHT22 // AM2302
#define DHT_PIN     2     // PWM for temperature/humidity
#define M_TIME      2000  // seconds between each measurement

// initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {

  Serial.begin(BIT_PER_SEC);
  
  dht.begin();
}

void loop() {

  delay(M_TIME);

  // reading temp|hum takes about 250 millisec
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  // validate the read values for hum/temp
  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read temperature and humidity");

    // set the values as inadequate so the interpreter will know
    humidity = -1;
    temp = -100;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  |  Temperature: ");
  Serial.print(temp);
  Serial.println(" *C");
}
