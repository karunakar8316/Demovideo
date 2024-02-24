#define TRIG_PIN 7
#define ECHO_PIN 6
#define ALERT_PIN 5

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ALERT_PIN, OUTPUT);
}

void loop() {
  long duration, distance;
  
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance based on the speed of sound
  distance = duration * 6 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Check if the sludge level exceeds the threshold (example: 20 cm)
  if (distance > 100) {
    // Sludge level is high, trigger the alert
    digitalWrite(ALERT_PIN, HIGH);
  } else {
    // Sludge level is normal, turn off the alert
    digitalWrite(ALERT_PIN, LOW);
  }
  
  delay(1000); // Wait for 1 second before taking the next reading
}
