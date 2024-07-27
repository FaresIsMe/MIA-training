// Motor A
int EnableA = 3;
int In1 = 4;
int In2 = 7;

// Motor B
int EnableB = 5;
int In3 = 6;
int In4 = 8;

int speed = 255; // Speed of motor (0-255)
int Time = 1000; // Time in milliseconds to move motor

/**
 * setup - it sets up the pins for later use 
 * in loop or any other function.
 * 
 * Returns nothing.
 */
void setup()
{
    // Set up motor A pins
    pinMode(EnableA, OUTPUT);
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);

    // Set up motor B pins
    pinMode(EnableB, OUTPUT);
    pinMode(In3, OUTPUT);
    pinMode(In4, OUTPUT);
    // Initialize serial monitor
    Serial.begin(9600);
}

/**
 * YawRight - Sets motor to move and stops motor B
 * to make a 90 turn right
 * 
 * Reeturns nothing.
 */
void YawRight()
{
    analogWrite(EnableA, speed);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    analogWrite(EnableB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    
    Serial.println("Yaw Right");
}


/**
 * YawLeft - Sets motor to move and stops motor B
 * to make a 90 turn left
 *
 * Returns nothing.
 */
void YawLeft()
{
    analogWrite(EnableA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);

    analogWrite(EnableB, speed);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    
    Serial.println("Yaw Right");
}
/**
 * forward - Sets motor to move forward
 * 
 * Returns nothing
 */
void forward()
{
    analogWrite(EnableA, speed);
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    analogWrite(EnableB, speed);
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    
    Serial.println("Forward");
}

/**
 * backward - Sets motor to move backward
 * 
 * Returns nothing
 */

void backward()
{
    analogWrite(EnableA, speed);
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);

    analogWrite(EnableB, speed);
    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
    
    Serial.println("Backward");
}
/**
 * loop - it does what it does
 * 
 * Returns nothing.
 */
void loop()
{
    YawRight();
    Serial.println("--------------");
    delay(1000);
    YawLeft();
    Serial.println("--------------");
    delay(1000);
    forward();
    Serial.println("--------------");
    delay(1000);
    backward();
    Serial.println("--------------");
    delay(1000);
}
