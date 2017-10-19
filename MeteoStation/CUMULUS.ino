#ifdef cumulus
void cumulus_output() {
#ifdef RTCclock      
	DateTime now = RTC.now();

	sprintf(capture_date, "%d-%02d-%02d", now.year(), now.month(), now.date());
	sprintf(capture_time, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

	Serial.print(F(" 0, 0, 0, "));
	Serial.print(capture_date);
	Serial.print(F(", "));
	Serial.print(capture_time);
#else
	Serial.print(F(" 0, 0, 0, 0, "));
	/*ReadMills = millis();
	Serial.print(ReadMills / 1000);*/
#endif

	Serial.print(F(", 0, "));
	Serial.print(((int)((HumidadeInt * 4) + 0.5) / 4));    // Result integer rounded to mearest quarter (Cumulus don't work with decimal places in humidity)
	Serial.print(F(", "));
	Serial.print(TemperaturaInt, 1);
	Serial.print(F(", "));
	if (Mode <= 1)
	{
		Serial.print(humidity);
		Serial.print(humidity2);
	}
	else    Serial.print(((int)(((HumidadeExt / 10) * 4) + 0.5) / 4));
	Serial.print(F(", "));
	Serial.print(temperature4 / 10, 1);
	Serial.print(F(", 0, 0, 0, "));
	Serial.print(pressure, 1);
	Serial.print(F(", "));
	Serial.print(averagew);
	Serial.print(F(", 0, "));
	Serial.print(gust);
	Serial.print(F(", 0, 0, "));
	Serial.print(winddr);
	Serial.print(F(", 0, 0, 0, "));
	Serial.print(rainf);
	Serial.print(F(", 0, 0, 0, "));
	Serial.print(rain);
	Serial.print(F(","));

	if (Mode > 0 && Solar_UV)
	{
		Serial.print(F(" "));
		Serial.print(SolarRad);
		Serial.print(F(","" "));
		Serial.print(IndiceUV, 1);
		Serial.print(F(","));
	}
	Serial.println(F(""));
	delay(500);
}
#endif
