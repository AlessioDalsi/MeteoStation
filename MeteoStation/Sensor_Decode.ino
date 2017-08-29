void Sensor_Decode() {

	if (((code.charAt(0) != 'x') && (code.charAt(4) == '0') && (code.charAt(9) == '0') && (code.charAt(10) == '0')) || ((code.charAt(0) != 'x') && (code.charAt(4) == '0') && (code.charAt(9) == '1') && (code.charAt(10) == '0')) || ((code.charAt(0) != 'x') && (code.charAt(4) == '0') && (code.charAt(9) == '0') && (code.charAt(10) == '1')))
	{
		checkPacket(0);
		if (validPacket)
		{
			{
				temperature = 0;
				for (int i = 0; i < 12; i++)
					if (code.charAt(i + 12) == '1') temperature += 1 << i;

				// Calculate negative temperature
				if ((temperature & 0x800) == 0x800)
				{
					temperature = temperature | 0xF000;
				}
				temperature4 = temperature;

				humidity = 0;
				humidity2 = 0;
				for (int i = 0; i < 4; i++)
				{
					if (code.charAt(i + 28) == '1') humidity += 1 << i;
					if (code.charAt(i + 24) == '1') humidity2 += 1 << i;
				}
			}

			read_BMP();
			Data_Output();

		}

	}

	if ((code.charAt(4) == '0') && (code.charAt(9) == '1') && (code.charAt(10) == '1') && (code.charAt(11) == '0') && (code.charAt(12) == '1') && (code.charAt(13) == '1') && (code.charAt(14) == '0'))
	{
		checkPacket(0);
		if (validPacket)

		{
			{
				rain = 0;
				for (int i = 0; i < 16; i++)
					if (code.charAt(i + 16) == '1') rain += 1 << i;

				rain = rain / 4;

				time2 = millis();
				elapsed2 = time2 - lastreadtime2;

				if (rain != rain2)
				{
					lastreadtime2 = millis();
					rainf = ((rain - rain2) * 3600) / (elapsed2 / 1000);
				}

				if (((rain == rain2) || (rain2 == 0)) && (elapsed2 >= 60000)) rainf = 0;

				if (rain != rain2) rain2 = rain;
			}
			Data_Output();

		}

	}
	else if ((code.charAt(4) == '0') && (code.charAt(9) == '1') && (code.charAt(10) == '1') && (code.charAt(12) == '1') && (code.charAt(13) == '0') && (code.charAt(14) == '0'))

	{
		checkPacket(0);
		if (validPacket)
		{
			averagew = 0;
			for (int i = 0; i < 8; i++)
				if (code.charAt(i + 24) == '1') averagew += 1 << i;

			averagew = averagew / 5.0;

		}
	}

	else if ((code.charAt(7) == '0') && (code.charAt(12) == '1') && (code.charAt(13) == '1') && (code.charAt(15) == '1') && (code.charAt(16) == '1') && (code.charAt(17) == '1'))
	{
		validPacket = true;
		for (int j = 0; j < 3; j++)
		{
			validPacket = code.charAt(j) == 'x' && validPacket;
			if (validPacket == false) j = 3;
		}
		if (validPacket) checkPacket(3);

		if (validPacket)

		{
			{
				windd = 0;
				for (int i = 0; i < 9; i++)
					if (code.charAt(i + 18) == '1') windd += 1 << i;

				gust = 0;
				for (int i = 0; i < 8; i++)
					if (code.charAt(i + 27) == '1') gust += 1 << i;

				gust = gust / 5.0;

				// Wind gust spike removal
				if (gust >= 50.0) gust = lastgust; // Some Auriol wind sensor, when have near strikes tends to report false 51m/s wind gusts
				lastgust = gust;
			}

			winddr = windDirectionsText[windd / 45];    // Convert numeric Wind Direction to Text

			Data_Output();

		}
	}

	else if ((code.charAt(4) == '0') && (code.charAt(9) == '1') && (code.charAt(10) == '1') && (code.charAt(12) == '1') && (code.charAt(13) == '1') && (code.charAt(14) == '1'))

	{
		checkPacket(0);
		if (validPacket)
		{
			{
				windd = 0;
				for (int i = 0; i < 9; i++)
					if (code.charAt(i + 15) == '1') windd += 1 << i;

				gust = 0;
				for (int i = 0; i < 8; i++)
					if (code.charAt(i + 24) == '1') gust += 1 << i;

				gust = gust / 5.0;
				// Wind gust spike removal
				if (gust >= 50.0) gust = lastgust; // Some Auriol wind sensor, when have near strikes tends to report false 51m/s wind gusts
				lastgust = gust;

			}

			winddr = windDirectionsText[windd / 45];    // Convert numeric Wind Direction to Text

			Data_Output();

		}
	}

}