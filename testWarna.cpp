void kategori() {
    if (ph_last >= 5.4 && outputValue_last >= 1.78) {
        if (ph_last <= 5.8 && outputValue <= 1.9) {
            lcd_kat_segar();
        } else {
            lcd_kat_busuk();
        }
    } else {
        lcd_kat_busuk();
    }
}

void lcd_kat_segar() {
    lcd.setCursor(0,0);
    lcd.print("Kategori");
    lcd.setCursor(0,1);
    lcd.print("Segar");
}

void lcd_kat_busuk() {
    lcd.setCursor(0,0);
    lcd.print("Kategori");
    lcd.setCursor(0,1);
    lcd.print("Busuk");
}