/*
 Name:		MeteoStation.ino
 Created:	24/08/2017 16:15:56
 Author:	aless
*/

#include <AC_DS3231.h>
#include <EEPROM.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

#pragma region dichiarazioni

#define TempInt_Source 1 
#define D_Units "kmh"
#define Mode 0

boolean Solar_UV = false;
float TemperaturaInt_offset = 0.0;			//Interior Temperature Fine Adjust
float pressure_offset = -0.9;				//Pressure Fine Adjust
float Local_Altitude = 84.0;				//Insert here altitude of your location in meters

unsigned long interval = 23000;				//Don't change

// ------- LCD --------
LiquidCrystal_I2C lcd(0x27, 20, 4);
byte lcd_L4_info = 1;
// --------------------

#define Receiver_PIN 8
#define Led1_PIN 2							//led di ricezione segnale radio (da confermare)
#define Led2_PIN 3

AC_DS3231 RTC;								//Orologio

//per l'rtc indirizzi 0x57 e 0x68

// ------ BMP085 -------					il nostro è BMP180 ma la libreria va bene uguale
#define BMP085_ADDRESS 0x77					// I2C address of BMP085
Adafruit_BMP085 bmp;
// ---------------------

#define nobits 36
#define smin 7500
#define smax 9900
#define semin 250
#define semax 750
#define lmin 1700
#define lmax 2300
#define hmin 3700
#define hmax 4300

float tempOld;
float TemperaturaInt, TempIntBMP;
float pressure;
float rain, rain2, rainf;
float Rain_DayBegin;
float averagew, gust;
float lastgust = 16;
float HumidadeExt, HumidadeInt;
float IndiceUV, temperature4;

short int temperature;
short int TemperaturaExt;
short int humidity, humidity2;
int windd;
unsigned int ADC0, ADC1, ADC4, SolarRad;	//ADC sta per convertitore analogico digitale
unsigned long ReadMillis;
unsigned long time, elapsed, lastreadtime, time1, elapsed1, lastreadtime1;
unsigned long time2, elapsed2, lastreadtime2;
long sensor[6];

byte TransmitterID;
byte WSDL_DataType;						//questo non serve

// ---- Direzioni Banderuola -------
static char windDirectionsText[8][3] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };

char DataPacket[27];
char capture_date[11];
char capture_time[11];
String winddr, code;
boolean validPacket;

// make some custom characters (crea i caratteri dei cuori ()):
byte heart[8] = {
	0b00000,
	0b01010,
	0b11111,
	0b11111,
	0b11111,
	0b01110,
	0b00100,
	0b00000
};

#pragma endregion

// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(9600);
	Wire.begin();
	bmp.begin(2);
	RTC.begin();


	pinMode(Receiver_PIN, INPUT);
	digitalWrite(Receiver_PIN, HIGH);

	pinMode(Led1_PIN, OUTPUT);

	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);

	init_LCD();
	//Rain_DayBegin = eepromReadFloat(30);

}

// the loop function runs over and over again until power down or reset
void loop() {

	code = RCode();						//funzione che riceve originali dai sensori
	Serial.print(code);

	Sensor_Decode();
}
