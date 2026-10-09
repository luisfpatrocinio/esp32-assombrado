#include <Arduino.h>
#include <BleGamepad.h>l

BleGamepad bleGamepad("Asssombrado", "Catavento", 100);

// Pinos disponíveis na sua fileira que não dão conflito no modo Digital
const int ldrEsquerda = 15;
const int ldrCentro = 2;
const int ldrDireita = 4;

void setup() {
  Serial.begin(115200);
  
  // Configura os pinos como entradas normais (botões)
  pinMode(ldrEsquerda, INPUT);
  pinMode(ldrCentro, INPUT);
  pinMode(ldrDireita, INPUT);

  bleGamepad.begin();
  Serial.println("ESP32 iniciado. Aguardando Bluetooth...");
}

void loop() {
  // Lê os sensores como se fossem botões digitais (HIGH = Lanterna, LOW = Escuro)
  bool estadoEsq = digitalRead(ldrEsquerda);
  bool estadoCen = digitalRead(ldrCentro);
  bool estadoDir = digitalRead(ldrDireita);

  if (bleGamepad.isConnected()) {
    
    // Controle Esquerda
    if (estadoEsq == HIGH) {
      bleGamepad.press(BUTTON_1);
    } else {
      bleGamepad.release(BUTTON_1);
    }

    // Controle Centro
    if (estadoCen == HIGH) {
      bleGamepad.press(BUTTON_2);
    } else {
      bleGamepad.release(BUTTON_2);
    }

    // Controle Direita
    if (estadoDir == HIGH) {
      bleGamepad.press(BUTTON_3);
    } else {
      bleGamepad.release(BUTTON_3);
    }
  }
  
  delay(50); // Pausa curta para estabilidade do jogo
}