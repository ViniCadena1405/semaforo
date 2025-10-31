#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 9, 8, 5, 4);

int amarelo = 6;
int verde = 2;
int vermelho = 3;

void setup()
{
  lcd.begin(16, 2);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
  // Verde: 4s
  mostrarTempo("Verde", verde, 4);

  // Amarelo: 2s
  mostrarTempo("Amarelo", amarelo, 2);

  // Vermelho: 6s
  mostrarTempo("Vermelho", vermelho, 6);
}

// Função que mostra contagem no LCD
void mostrarTempo(String cor, int pino, int segundos) {
  // Garante que só o LED da cor certa acenda
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(pino, HIGH);

  for (int i = segundos; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sinal: ");
    lcd.print(cor);
    lcd.setCursor(0, 1);
    lcd.print("Tempo: ");
    lcd.print(i);
    lcd.print("s   ");
    delay(1000);
  }

  digitalWrite(pino, LOW);
}
