

// C++ code
//
int LDR_value, BUZZ = 3;

/**
* setup - startups are here
*
*Returns nothing
*/
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
/**
 * loop - continuously runs and main tasks happen here
 * 
 * Returns nothing
 */
void loop()
{
	LDR_value = analogRead(A0);
  	Serial.println(LDR_value);
  	delay(100);
    if (LDR_value > 500)
  	tone(BUZZ, 100, 1000);
}