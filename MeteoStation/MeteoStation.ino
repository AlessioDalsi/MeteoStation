/*
 Name:		MeteoStation.ino
 Created:	24/08/2017 16:15:56
 Author:	aless
*/

#include <Adafruit_BMP085.h>
#include <AC_DS3231.h>
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

// ------- LCD --------
LiquidCrystal_I2C dlc(0x27, 20, 4);
byte lcd_L4_info = 1;
// --------------------

#define Receiver_PIN 8
#define Led1_PIN 2							//led di ricezione segnale radio (da confermare)

AC_DS3231 RTC;								//Orologio

// ------ BMP085 -------					il nostro è BMP180 ma la libreria va bene uguale
#define BMP085_ADDRESS 0x77					// I2C address of BMP085
Adafruit_BMP085 bmp;
// ---------------------

#pragma endregion



// the setup function runs once when you press reset or power the board
void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {

}
