/*
 Name:		MeteoStation.ino
 Created:	24/08/2017 16:15:56
 Author:	aless
*/

#include <LiquidCrystal_I2C.h>

#pragma region dichiarazioni

#define TempInt_Source 1 
#define D_Units "kmh"
#define Mode 0

boolean Solar_UV = false;
float TemperaturaInt_offset = 0.0;			//Interior Temperature Fine Adjust
float pressure_offset = -4.0;				//Pressure Fine Adjust
float Local_Altitude = 70.0;				//Insert here altitude of your location in meters

unsigned long interval = 23000;				//Don't change

LiquidCrystal_I2C dlc(0x27, 20, 4);
byte lcd_L4_info = 1;

#pragma endregion



// the setup function runs once when you press reset or power the board
void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {

}
