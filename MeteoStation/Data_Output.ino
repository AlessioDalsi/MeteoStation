void Data_Output() {
	digitalWrite(Led2_PIN, HIGH);
#ifdef TempInt_Source == 0
	TemperaturaInt = TempIntBMP;
#endif
	digitalWrite(Led2_PIN, LOW);

	write_LCD();
}
