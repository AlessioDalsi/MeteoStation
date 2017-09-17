void write_LCD() {


	lcd.clear();
	lcd.print(temperature4 / 10, 1);

	/*HumidadeExt = ((humidity*10.0) + humidity2)*10.0;
	char lcd_hours[20];

	lcd.setCursor(0, 1);
	lcd.print(F("                    "));
	lcd.setCursor(0, 2);
	lcd.print(F("Out:"));
	if (temperature4 >= 100) lcd.setCursor(5, 2);
	else lcd.setCursor(6, 2);
	lcd.print(temperature4 / 10, 1);
	lcd.write(B11011111);   // Degree Symbol
	lcd.print(F("C  "));
	if (HumidadeExt > 990) lcd.setCursor(13, 2);
	else lcd.setCursor(14, 2);
	lcd.print(HumidadeExt / 10, 0);
	lcd.print(F("% H"));

	lcd.setCursor(0, 3);
	lcd.print(F("                    "));

	float Rain_Today = rain - Rain_DayBegin;

	if (Rain_Today == 0.0 && lcd_L4_info == 3) lcd_L4_info += 1;
	if (SolarRad == 0 && lcd_L4_info > 3) lcd_L4_info = 1;

	switch (lcd_L4_info)
	{
	case 1:
	{
		lcd.setCursor(1, 3);
		lcd.print(F("P. Atm: "));
		lcd.print(pressure, 1);
		lcd.print(F(" mB"));
		break;
	}
	case 2:
	{
		lcd.setCursor(1, 3);
		lcd.print(F("Wind : "));
		if (D_Units == "mph") {
			lcd.print(averagew * 2.236, 1);     // convert m/s to mph
			lcd.print(F(" mph "));
		}
		else {
			lcd.print(averagew * 3.6, 1);      // convert m/s to Km/h
			lcd.print(F(" Kmh "));
		}
		lcd.print(winddr);
		break;
	}
	case 3:
	{
		lcd.setCursor(1, 3);
		lcd.print(F("Rain : "));
		lcd.print(Rain_Today, 2);
		lcd.print(F(" mm/m2"));
		break;
	}
	case 4:
	{
		lcd.setCursor(2, 3);
		lcd.print(F("UV Index : "));
		lcd.print(IndiceUV, 1);
		break;
	}
	case 5:
	{
		lcd.setCursor(1, 3);
		lcd.print(F("Solar R.: "));
		lcd.print(SolarRad);
		lcd.print(F(" Wm2"));
		break;
	}
	}

	if (lcd_L4_info <= 4) lcd_L4_info += 1;
	else lcd_L4_info = 1;
	*/
}
