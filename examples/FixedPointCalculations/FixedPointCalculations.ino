#include <FixedPoints.h>
#include <FixedPointsCommon.h>

void TestQ8x8(void)
{
	Serial.println(F("The size of Q8x8 on your system is:"));
	Serial.println(sizeof(Q8x8));
	Serial.println();
	
	Q8x8 a = 1.5;
	Serial.println(F("Displaying a as float:"));
	Serial.println(static_cast<float>(a));
	Serial.println(F("Displaying the integer part of a"));
	Serial.println(a.GetInteger());
	Serial.println();
	
	Q8x8 b = 8.0;
	Serial.println(F("Displaying b as float:"));
	Serial.println(static_cast<float>(b));
	Serial.println(F("Displaying the integer part of b"));
	Serial.println(b.GetInteger());
	Serial.println();

	Serial.println(F("Displaying a + b as float:"));
	Serial.println(static_cast<float>(a + b));
	Serial.println();

	Serial.println(F("Displaying a - b as float:"));
	Serial.println(F("(Note the underflow due lack of sign bit)"));
	Serial.println(static_cast<float>(a - b));
	Serial.println();

	Serial.println(F("Displaying b - a as float:"));
	Serial.println(static_cast<float>(b - a));
	Serial.println();
	
	Serial.println(F("Displaying a * b as float:"));
	Serial.println(static_cast<float>(a * b));
	Serial.println();
	
	Serial.println(F("Displaying a / b as float:"));
	Serial.println(F("This is incorrect due to low resolution"));
	Serial.println(static_cast<float>(a / b));
	Serial.println();
}

void TestSQ7x8(void)
{

	Serial.println(F("The size of SQ7x8 on your system is:"));
	Serial.println(sizeof(SQ7x8));
	Serial.println();
	
	SQ7x8 a = 1.5;
	Serial.println(F("Displaying a as float:"));
	Serial.println(static_cast<float>(a));
	Serial.println(F("Displaying the integer part of a"));
	Serial.println(a.GetInteger());
	Serial.println();
	
	SQ7x8 b = 8.0;
	Serial.println(F("Displaying b as float:"));
	Serial.println(static_cast<float>(b));
	Serial.println(F("Displaying the integer part of b"));
	Serial.println(b.GetInteger());
	Serial.println();

	Serial.println(F("Displaying a + b as float:"));
	Serial.println(static_cast<float>(a + b));
	Serial.println();

	Serial.println(F("Displaying a - b as float:"));
	Serial.println(F("(Note the sign bit makes this valid.)"));
	Serial.println(static_cast<float>(a - b));
	Serial.println();

	Serial.println(F("Displaying b - a as float:"));
	Serial.println(static_cast<float>(b - a));
	Serial.println();
	
	Serial.println(F("Displaying a * b as float:"));
	Serial.println(static_cast<float>(a * b));
	Serial.println();
	
	Serial.println(F("Displaying a / b as float:"));
	Serial.println(F("This is incorrect due to low resolution"));
	Serial.println(static_cast<float>(a / b));
	Serial.println();
}

void setup()
{
	while(!Serial);

	TestQ8x8();
	TestSQ7x8();
}

void loop()
{
}
