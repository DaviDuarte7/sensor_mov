const int trigPin = 18;  // Pino GPIO 18
const int echoPin = 19;  // Pino GPIO 19
 float distancia;
void setup() {
    Serial.begin(115200);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    if(distancia < 15){
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(15);
    }else{
        digitalWrite(trigPin, LOW);
    }
    long duration = pulseIn(echoPin, HIGH);
    float distancia = (duration * 0.0343) / 2;  // Calculando a distância em cm

    Serial.print("Distância: ");
    Serial.print(distancia);
    Serial.println(" cm");

    delay(500);  // Aguarda 0,5 segundos para a próxima leitura
}
