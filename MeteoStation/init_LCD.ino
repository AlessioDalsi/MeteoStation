void init_LCD() {

	//avvia LCD con 20 caratteri e 4 linee inizializzato nel main

	lcd.begin();
	lcd.backlight();

	lcd.setCursor(4, 0);							//inizia dal carattere 3 linea 0
	lcd.print("Meteo Station");
	delay(1000);
	lcd.setCursor(7, 2);
	lcd.print("v 1.0");
	delay(2000);
	lcd.setCursor(6, 3);
	lcd.print("(Alpha)");
	delay(5000);
	lcd.clear();

}
