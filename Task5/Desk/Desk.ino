#include <string.h>
#include <Wire.h>


char *message;
int length = 0, i = 0;
void setup() 
{
    Wire.begin();
    Serial.begin(9600);
}

/**
 * loop - main loop function
 * 
 * Returns nothing
 */
void loop()
{
    Wire.requestFrom(8, 32);
    length = Wire.available(); 
    message = (char *)malloc(length + 1);
    
    while(Wire.available())
    {
        message[length - i - 1] = Wire.read();
        i++;
    }
    Serial.print("Received message from master: ");
    Serial.println(message);
}



void loop()
{
    if (Serial.available()) 
    {
        length = Serial.read();

        for (int i = 0; i < length; i++)
        {
            message[i] = Serial.read();
        }
        message[length] = '\0';

        if (length > 0)
        {

            Serial.print("Received message: ");
            Serial.println(message);
            Serial.println(length);
        }
        delay(1000);  
    }
  
  	send_to_i2c(message, length);
}

void send_to_i2c(char *message, int length)
{
    Wire.beginTransmission(length);
    Wire.write(length);
    Wire.write(message);
    Wire.endTransmission();
}

void receiveEvent(int howMany)
{
    int i = 0;
    while(1 < Wire.available())
    {
        message[i] = Wire.read();
        i++
    }
    message[i] = '\0';
    Serial.print("Received message from Master: ");
    Serial.println(message);
           
}