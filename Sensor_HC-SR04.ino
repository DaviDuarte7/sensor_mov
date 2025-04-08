// Pin definitions for HC-SR04 sensor
const int trigPin = 16;  // GPIO 18 for Trig (signal emission)
const int echoPin = 18;  // GPIO 19 for Echo (signal reception)
const int ledPin = 32;

// Defining variables
long duration;  // Variable to store the time the Echo takes to return
float distance;  // Variable to store the calculated distance

void setup() {
  // Initializes serial communication for monitoring
  Serial.begin(115200);

  // Configures the Trigger and Echo pins
  pinMode(trigPin, OUTPUT);  // Set Trig pin as output
  pinMode(echoPin, INPUT);   // Set Echo pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
}

void loop() {
  digitalWrite(trigPin, LOW);  // Ensures the Trig pin is LOW
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);  // Sends a 10-microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);  // Measures the duration of the returned signal
  distance = (duration * 0.0343) / 2;  // Calculates the distance
  
  Serial.print("Distance: ");
  Serial.print(distance);  // Prints the distance
  Serial.println(" cm");

  // Logic to turn on the LED based on distance
  if (distance < 10) {  // If the distance is less than 10 cm
    digitalWrite(ledPin, HIGH);  // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
  }

  delay(500);  // Delay between readings
}
