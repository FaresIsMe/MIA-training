
// Variables for ulrasonic sensor.
int trig = 3;
int echo = 4;
long duration, distance;

//prototypes
long ultrasonic();


/**
 * setup - Function to initialize the ultrasonic sensor.
 * 
 * Returns nothing.
 */
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


/**
 * loop - it does what it does
 * 
 * Returns nothing.
 */
void loop()
{
    distance = ultrasonic();

    if (distance < 332)
    {
        Serial.println("Object is detected in range!");
    }
    else Serial.println("No object detected in range.");
    // Serial.print("Distance: ");
    // Serial.println(distance);
}


/**
 * ultrasonic - Function to measure the distance using ultrasonic sensor.
 * 
 * returns the distance in centimeters.
 */
long ultrasonic()
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 29.1;
    return (distance);
}