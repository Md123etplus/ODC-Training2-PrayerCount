#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);//16 columns 2 lines

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(115200);//allow us to show some stuff in console
  lcd.init();   // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(3,0);
}

void loop() {
  
  // lcd.print("Hello, world!");

  static int compteur=0;
  // put your main code here, to run repeatedly:
  int addButton=digitalRead(2);
  int resetButton=digitalRead(3);
  if(addButton){
    compteur++;
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print(compteur);

    // Serial.println(compteur);
  }
  if(resetButton){
    compteur=0;
    lcd.clear();
    // Serial.println(compteur);
    lcd.setCursor(3,0);
    lcd.print(compteur);
  }
  if(compteur==20000){
    lcd.print("Compte limite atteinte!!! Retour a zero automatique");
    Serial.print(compteur);
    Serial.print(" --> 0");
    Serial.println(" ");  

  }
  delay(150);
}
