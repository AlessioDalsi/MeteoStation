void Data_Output() {
	digitalWrite(Led2_PIN, HIGH);
	if (TempInt_Source == 0) {
		TemperaturaInt = TempIntBMP;
	}
	digitalWrite(Led2_PIN, LOW);

	write_LCD();
}
