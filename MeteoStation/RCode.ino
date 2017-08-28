String RCode() {
	String code = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	long startMicros = micros(), endMicros;
	if (bitRead(PINB, 0)) return "";
	while (!bitRead(PINB, 0))
	{
		if ((micros() - startMicros) > smax)
			return "";
	}
	if ((micros() - startMicros) < smin)
		return "";
	startMicros = micros();
	while (bitRead(PINB, 0))
	{
		if ((micros() - startMicros) > semax)
			return "";
	}
	if ((micros() - startMicros) < semin)
		return "";
	for (int i = 0; i < nobits; i++)
	{
		startMicros = micros();
		while (!bitRead(PINB, 0))
		{
			if ((micros() - startMicros) < 1);
		}
		endMicros = micros();
		if (((endMicros - startMicros) > lmin) && ((endMicros - startMicros) < lmax))
			code.setCharAt(i, '0');
		else if (((endMicros - startMicros) > hmin) && ((endMicros - startMicros) < hmax))
			code.setCharAt(i, '1');

		startMicros = micros();
		while (bitRead(PINB, 0))
		{
			if ((micros() - startMicros) > semax)
				return "";
		}
		if ((micros() - startMicros) < semin)
			return "";
	}

	if (nobits == 36) {
		return code;
	}
	else
		return "";
}
