void lcd_kat_segar() {
    if (Firebase.RTDB.setString(&fbdo, "test/kategori", "Segar")) {
        Serial.println("Data Kategori Berhasil Dikirim");
        Serial.println("PATH: " + fbdo.dataPath());
        Serial.println("TYPE: " + fbdo.dataType());
    } else {
        Serial.println("Data Kategori Gagal Dikirim");
        Serial.println(fbdo.errorReason());
    }
    lcd.setCursor(0,0);
    lcd.print("    Kategori    ");
    lcd.setCursor(0,1);
    lcd.print("     Segar      ");
}

void lcd_kat_busuk() {
    if (Firebase.RTDB.setString(&fbdo, "test/kategori", "Busuk")) {
        Serial.println("Data Kategori Berhasil Dikirim");
        Serial.println("PATH: " + fbdo.dataPath());
        Serial.println("TYPE: " + fbdo.dataType());
    } else {
        Serial.println("Data Kategori Gagal Dikirim");
        Serial.println(fbdo.errorReason());
    }
    lcd.setCursor(0,0);
    lcd.print("    Kategori    ");
    lcd.setCursor(0,1);
    lcd.print("     Busuk      ");
}

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

void kat_warna() {
    if (nilair >= 50 && nilaig >= 125){
        if (nilair <= 87 && nilaig <= 212) {
            kategori();
        } else {
            return;
        }
    } else if (nilair >= 50 && nilaib >= 100){
        if (nilair <= 87 && nilaig <= 181) {
            kategori();
        } else {
            return;
        }
    } else if (nilaig >= 125 && nilaib >= 100){
        if (nilair <= 212 && nilaig <= 181) {
            kategori();
        } else {
            return;
        }
    } else {
        lcd_kat_busuk();
    }
}

/*
void kat_warna1() {
    if (nilair >= 50 && nilaig >= 125 && nilaib >= 100) {
        if (nilair <= 87 && nilaig <= 212 && nilaib <= 181) {
            kategori();
        } else {
            lcd_kat_busuk();
        }
    } else {
        lcd_kat_busuk();
    }
}
*/