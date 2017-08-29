boolean checkPacket(int initbyte) {
	validPacket = true;
	for (int j = initbyte; j < 34; j++)
	{
		validPacket = code.charAt(j) != 'x' && validPacket;
		if (validPacket == false) j = 34;
	}
	if (validPacket) digitalWrite(Led1_PIN, HIGH);
	delay(15);
	digitalWrite(Led1_PIN, LOW);
	return validPacket;
}
