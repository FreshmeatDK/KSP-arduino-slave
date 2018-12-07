/*
 Name:		KSPSlave.ino
 Created:	12/1/2018 8:45:05 PM
 Author:	Jesper
*/


#include <Wire.h>

byte ctrlDta;
byte ctrlArray[2];
uint8_t numbytes = 1;

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

void packAndSend()
{
	Serial.write(B10101010);
	for (int i = 0; i < numbytes; i++)
	{
		if ((ctrlArray[i] = B11001100) || (ctrlArray[i] = B00001111) || (ctrlArray[i] = B10101010))
		{
			Serial.write(B00001111);
		}
		Serial.write(ctrlArray[i]);
	}
	Serial.write(B11001100);
}