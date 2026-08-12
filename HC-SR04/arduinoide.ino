#define TRIG_PIN 6
#define ECHO_PIN 7

void setup() {
  Serial.begin(9600);         // 시리얼 모니터 시작
  pinMode(TRIG_PIN, OUTPUT);  // Trig 핀 출력
  pinMode(ECHO_PIN, INPUT);   // Echo 핀 입력
}

void loop() {
  long duration, distance;

  // Trig 핀에서 10µs 펄스 발생
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Echo 핀에서 HIGH 유지 시간 측정 (µs 단위)
  duration = pulseIn(ECHO_PIN, HIGH);

  // 거리 계산 (음속 약 340m/s → 29.1µs에 1cm 이동)
  distance = duration * 0.034 / 2; // 왕복이므로 2로 나눔

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // 0.5초마다 측정
}
