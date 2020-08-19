// Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop()
{
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("CORES RGB");
  setColor(255, 0, 0);  // red
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("VERMELHO       ");
  delay(1000);
  setColor(0, 255, 0);  // green
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("VERDE          ");
  delay(1000);
  setColor(0, 0, 255);  // blue
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("AZUL           ");
  delay(1000);
  setColor(255, 255, 0);  // yellow
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("AMARELO        ");
  delay(1000);  
  setColor(80, 0, 80);  // purple
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("ROXO            ");
  delay(1000);
  setColor(0, 255, 255);  // aqua
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("AZUL CLARO      ");
  delay(1000);
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
