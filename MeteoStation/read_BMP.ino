void read_BMP() {
	TempIntBMP = bmp.readTemperature() + TemperaturaInt_offset;
	float uncomp_pressure = bmp.readPressure();
	//    pressure = (uncomp_pressure/pow((1-Local_Altitude/44330),5.255));
	pressure = ((uncomp_pressure / pow((1 - Local_Altitude / 44330), 5.255)) / 100.0) + pressure_offset;
}
