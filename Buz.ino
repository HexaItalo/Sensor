const int mq9Pin = A0;      // Pino analógico do sensor MQ-9
const int buzzer = 8;    // Pino digital do buzzer
const int limiteGas = 200;  // Valor limite de gás (ajuste conforme necessário)

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tone(buzzer, 500);
  int valorGas = analogRead(mq9Pin); // Lê o valor do sensor MQ-9

  Serial.print("Valor lido do MQ-9: ");
  Serial.println(valorGas);

  
  if (valorGas > limiteGas) {
     // Ativa o buzzer
    digitalWrite(buzzer,HIGH);
     tone(buzzer, 500);
    Serial.println("⚠️ Gás detectado!");
  } else {
    noTone(buzzer);  // Desliga o buzzer
  }

  delay(5000); // Espera 1 segundo antes de ler de novo
}
