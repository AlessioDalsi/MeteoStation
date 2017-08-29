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

}