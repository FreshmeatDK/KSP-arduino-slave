/*
 Name:		KSPSlave.ino
 Created:	12/1/2018 8:45:05 PM
 Author:	Jesper
*/


#include <Wire.h>

byte ctrlDta;

void setup() 
{
	Serial.begin(9600);
	Wire.begin(8);
	Wire.onReceive(receiveInfo);
}


void loop() 
{
	delay(10);
	//Serial.println("wait");
}

void receiveInfo(int numbytes)
{
	while (Wire.available())
	{
		ctrlDta = Wire.read();

	}
	//Serial.println("Data");
	Serial.write((byte*)&ctrlDta, sizeof(ctrlDta));
}
