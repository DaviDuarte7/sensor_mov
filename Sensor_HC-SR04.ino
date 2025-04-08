// Definições dos pinos do sensor HC-SR04
const int trigPin = 16;  // Pino GPIO 18 para o Trig (emissão do sinal)
const int echoPin = 18;  // Pino GPIO 19 para o Echo (recepção do sinal)
const int ledPin = 32;
// Definindo variáveis
long duration;  // Variável para armazenar o tempo que o Echo leva para retornar
float distancia;  // Variável para armazenar o cálculo da distância

void setup() {
  // Inicializa a comunicação serial para monitoramento
  Serial.begin(115200);

  // Configura os pinos de Trigger e Echo
  pinMode(trigPin, OUTPUT);  // Pino do Trig como saída
  pinMode(echoPin, INPUT);   // Pino do Echo como entrada
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);  // Garante que o Trig está em LOW
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);  // Envia um pulso de 10 microssegundos
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);  // Mede o tempo do sinal retornado
    distancia = (duration * 0.0343) / 2;  // Calcula a distância
  
  Serial.print("Distância: ");
  Serial.print(distancia);  // Imprime a distância
  Serial.println(" cm");

  // Lógica para acender o LED baseado na distância
  if (distancia < 10) { // Se a distância for menor que 10 cm
    digitalWrite(ledPin, HIGH);  // Acende o LED
  } else {
    digitalWrite(ledPin, LOW);   // Apaga o LED
  }

  delay(500);  // Delay entre leituras
}