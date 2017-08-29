void Rain_updates()
{

	DateTime now = RTC.now();

	if ( now.date() != eepromReadInt(35))
	{
	eepromWriteFloat(30, rain);
	eepromWriteInt(35, now.date());
	//Serial.println(F("Rain_DayBegin -> Writing to Eeprom"));
	Rain_DayBegin = rain;
	}
}
