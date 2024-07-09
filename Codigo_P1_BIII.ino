#include <Adafruit_NeoPixel.h>

#define PIN_Leds 12
#define NUMPIXELS 16

#define Trigger 3
#define Echo 4

#define A 5
#define B 6
#define C 7
#define D 8
#define E 9
#define F 10
#define G 11

Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(NUMPIXELS, PIN_Leds, NEO_GRB + NEO_KHZ800);

int conteo_personas = 0;
float Medida;
float MedidaAnterior = 0;

void setup() {
  Serial.begin(9600);  // Inicializar comunicación serial
  neopixel.begin();
  neopixel.setBrightness(50);

  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);

  encenderNeoPixelVerde();
}

void loop() {
  Medida = LecturaDistancia();
  Serial.println(Medida);
  delay(100);
  if (Medida >= 6 && Medida <= 10 && (MedidaAnterior < 6 || MedidaAnterior > 10)) {
    conteo_personas++;
    if (conteo_personas > 10) {
      conteo_personas = 10;  // Para limitar el conteo a 10
    }
    actualizarDisplay();
    Serial.println(conteo_personas);
  }
  MedidaAnterior = Medida;
}

float LecturaDistancia() {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  float sensor = pulseIn(Echo, HIGH);
  float distancia = sensor / 59;
  return distancia;
}

void actualizarDisplay() {
  apagarDisplay();

  if (conteo_personas == 0) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
  } else if (conteo_personas == 1) {
    encenderNeoPixelVerde();
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
  } else if (conteo_personas == 2) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 3) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 4) {
    encenderNeoPixelVerde();
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 5) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 6) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 7) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
  } else if (conteo_personas == 8) {
    encenderNeoPixelVerde();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (conteo_personas == 9) {
    encenderNeoPixelRojo();
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    delay(400);
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);


  }
}

void encenderNeoPixelVerde() {
  for (int i = 0; i < NUMPIXELS; i++) {
    neopixel.setPixelColor(i, neopixel.Color(0, 255, 0));
  }
  neopixel.show();
}

void encenderNeoPixelRojo() {
  for (int i = 0; i < NUMPIXELS; i++) {
    neopixel.setPixelColor(i, neopixel.Color(255, 0, 0));
  }
  neopixel.show();
}

void apagarDisplay() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
