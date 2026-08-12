// 전처리문: 헤더파일 불러오기
#include "DHT.h" // 사용자 정의 또는 외부 다운로드 헤더

#define DHTPIN 2      // 데이터 핀
#define DHTTYPE DHT11 // 센서 종류 지정 (DHT11)

// 온습도센서 처리 객체 dht 생성됨!
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin(); // 센서 초기화
}

void loop() {
  delay(3000); // 측정 주기가 느리므로 딜레이가 짧을 필요 없음

  float h = dht.readHumidity();    // 습도 값 읽기
  float t = dht.readTemperature(); // 섭씨 온도 값 읽기

  // 오류 체크
  // isnan(x) : x가 유효한 숫자가지? bool 
  if (isnan(h) || isnan(t)) {
    Serial.println("DHT11 센서에서 데이터를 읽을 수 없습니다!");
    return;
  }

  // 값 출력
  Serial.print("습도: ");
  Serial.print(h);
  Serial.print("%, ");

  Serial.print("온도: ");
  Serial.print(t);
  Serial.println("*C");
}
