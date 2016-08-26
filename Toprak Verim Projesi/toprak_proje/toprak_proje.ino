#include <DHT.h> // dht11 kütüphanesini ekliyoruz.
#include <LiquidCrystal.h> // Ekran kütüphanesini ekliyoruz.

// RGB LED Tanımlamaları
int const red_pin = 11;
int const green_pin = 13;
int const blue_pin = 12;

// Nem Sensörü Tanımlamaları
#define DHT11PIN 2 
#define DHTTYPE DHT11
DHT dht(DHT11PIN, DHTTYPE);
float nemdeger;
float isideger;

// Toprak Nem Sensörü Tanımlamaları
int const toprak_pin = 0;
float topraknem;

// Piezo Buzzler Tanımlamaları
int const buzzer_pin = 3;

// Ekran Tanımlamaları
int const rs_pin = 10;
int const e_pin = 9;
int const db4 = 4;
int const db5 = 5;
int const lcd1 = 6;


LiquidCrystal lcd(10, 9, 4, 5, 6, 7);

void setup() {
  // Seri İletişimi Başlatalım
  Serial.begin(9600);
  
  // RGB LED Kurulumu
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);

  // Nem Sensörü Kurulumu
  pinMode(DHT11PIN,INPUT);
  dht.begin();

  // Toprak Nem Sensörü Kurulumu
  pinMode(toprak_pin,INPUT);

  // Buzzer Kurulumu
  pinMode(buzzer_pin,OUTPUT);

  // Ekran Kurulumu
  lcd.begin(1, 1);
  lcd.print("Ekran Calisiyor");
}

void loop() {
  Serial.println("Toprak Nem Projesi");
  // Ortam nemini aldık
  nemdeger = dht.readHumidity();
  // Ortam isisini aldık
  isideger = dht.readTemperature();
  // Toprak nem değerini aldık
  topraknem = analogRead(toprak_pin);

  // Toprak Nem, Ortam Nem ve Ortam Isı değerlerini 
  // 16x2 ekranda ve seri ekranda yazdırdık.

  Serial.print("Ortam Nem:");
  Serial.println(nemdeger);
  Serial.print("Ortam Isi:");
  Serial.println(isideger);
  Serial.print("Toprak Nem:");
  Serial.println(topraknem);

  lcd.begin(1,1);
  lcd.print("Nem/Isi/TNem");
  lcd.begin(1,2);
  lcd.print((int)nemdeger);
  lcd.begin(7,2);
  lcd.print((int)isideger);
  lcd.begin(13,2);
  lcd.print((int)topraknem);

  // Ortam Isı değerlerini kontrol edelim

  if (nemdeger>80)
  {
    Serial.println("Yuksek ortam nemi");
    lcd.begin(1,1);
    lcd.print("Yuksek Ort Nem");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, HIGH);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, LOW);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else if (nemdeger<60)
  {
    Serial.println("Dusuk ortam nemi");
    lcd.begin(1,1);
    lcd.print("Dusuk Ort Nemi");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, HIGH);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else
  {
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, HIGH);
    digitalWrite(blue_pin, LOW);
  }

  
  if (isideger>25)
  {
    Serial.println("Yuksek ortam isisi");
    lcd.begin(1,1);
    lcd.print("Yuksek Ort Isisi");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, HIGH);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, LOW);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else if (nemdeger<10)
  {
    Serial.println("Dusuk ortam isisi");
    lcd.begin(1,1);
    lcd.print("Dusuk Ort Isisi");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, HIGH);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else
  {
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, HIGH);
    digitalWrite(blue_pin, LOW);
  }

  
  if (topraknem>80)
  {
    Serial.println("Yüksek toprak nemi");
    lcd.begin(1,1);
    lcd.print("Yuksek Toprak Nemi");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, HIGH);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, LOW);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else if (nemdeger>60)
  {
    Serial.println("Dusuk toprak nemi");
    lcd.begin(1,1);
    lcd.print("Dusuk Toprak Nemi");
    lcd.noDisplay();
    delay(500);
    lcd.display()
    delay(500);
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, LOW);
    digitalWrite(blue_pin, HIGH);

    beep(50);
    beep(50);
    beep(50);
    delay(1000);
  }
  else
  {
    digitalWrite(red_pin, LOW);
    digitalWrite(green_pin, HIGH);
    digitalWrite(blue_pin, LOW);
  }

}
