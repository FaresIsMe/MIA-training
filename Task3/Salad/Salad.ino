#include <Servo.h>

Servo Rat;

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

int LDR_value, BUZZ = 12; // Buzzer sensor pin

int x = 0, y = 0; //Location variables

// Variables for ulrasonic sensor.
int trigF = 10, echoF = 11; //foward US sensor
long durationF, distanceF;
int trigR = 2, echoR = 13; //right US sensor
long durationR, distanceR;
int trigL = A1, echoL = A2; //left US sensor
long durationL, distanceL;


int Time = 1000;

int direction = 3;

int X = 0, Y = 0; //Location variables


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

    // Set up LDR sensor pin
    pinMode(BUZZ, OUTPUT);

    // Initialize serial monitor
    Serial.begin(9600);

    // Attach the Servo object to pin 9
    Rat.attach(9);
}


/**
 * loop - it does what it does
 * 
 * Returns nothing.
 */
void loop()
{
    forward();
    if (distanceF < 330)
    {
        if (distanceL < 330 || distanceR < 330)
        {
            if (distanceL < 330)
            {
                direction = 1;
                YawRight();
                delay(Time);
                forward();
                delay(Time);
                YawRight();
            }
            else if (distanceR < 330)
            {
                direction = 2;
                YawLeft();
                delay(Time);
                forward();
                delay(Time);
                YawLeft();
            }
        }
        else if (direction == 1)
        {
            direction = 2;
            YawLeft();
            delay(Time);
            forward();
            delay(Time);
            YawLeft();
            updateLocation(2);
        }
        else if (direction == 2)
        {
            direction = 1;
            YawRight();
            delay(Time);
            forward();
            delay(Time);
            YawRight();
            updateLocation(1);
        }
    }
}

void updateLocation(int upORdown)
{
    if (upORdown == 1)
    {
        X += 1;
        Y += 1;
    }
    else if (upORdown == 2)
    {
        X -= 1;
        Y -= 1;
    }
    Serial.print("X: ");
    Serial.print(X);
    Serial.print(", Y: ");
    Serial.println(Y);
}

/**
 * Buzzer - checks LDR sensor and triggers the buzzer
 * 
 * Returns nothing.
 */
void LDR_Buzz()
{
    LDR_value = analogRead(A0);
  	Serial.println(LDR_value);
  	delay(100);
    if (LDR_value > 500)
    {
  	    tone(BUZZ, 100, 1000);
        controlServo();
    }
}
/**
 * controlServo - controls the Servo to rotate to 90 
 * degrees and then back 0
 * 
 *returns nothing.
 */
void controlServo()
{
    Rat.write(90);
    delay(1000);
    Rat.write(0);
    Serial.println("Mine removed!");
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
    ultrasonic_calls();
    
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
    ultrasonic_calls();
    
    Serial.println("Backward");
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
    ultrasonic_calls();
    
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
    ultrasonic_calls();
    
    Serial.println("Yaw Right");
}

/**
 * ultrasonic_calls - Calls the ultrasonic sensors and 
 * prints the distances
 * 
 * 
 */
void ultrasonic_calls()
{
    distanceF = front_sonic();
    distanceR = right_sonic();
    distanceL = left_sonic();
    // Serial.print("Distance from front sensor: ");
    // Serial.print(distanceF);
    // Serial.print(" cm");
    // Serial.print(", ");
    // Serial.print("Distance from right sensor: ");
    // Serial.print(distanceR);
    // Serial.print(" cm");
    // Serial.print(", ");
    // Serial.print("Distance from left sensor: ");
    // Serial.print(distanceL);
    // Serial.print(" cm");
    // Serial.println();

}

int left_sonic()
{
    digitalWrite(trigF, LOW);
    delayMicroseconds(2);
    digitalWrite(trigF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigF, LOW);
    durationL = pulseIn(echoF, HIGH);
    distanceL = (durationL / 2) / 29.1;
    return distanceL;
}

int right_sonic()
{
    digitalWrite(trigR, LOW);
    delayMicroseconds(2);
    digitalWrite(trigR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigR, LOW);
    durationR = pulseIn(echoR, HIGH);
    distanceR = (durationR / 2) / 29.1;
}

int front_sonic()
{
    digitalWrite(trigF, LOW);
    delayMicroseconds(2);
    digitalWrite(trigF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigF, LOW);
    durationF = pulseIn(echoF, HIGH);
    distanceF = (durationF / 2) / 29.1;
}

