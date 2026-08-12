# Arduino
<H1>ESP-01 모듈</H1>
ESP-8266 모듈 : Wi-Fi 무선 통신 기능을 탑재한 저전력 마이크로컨트롤러
ESP-01 모듈 : ESP-8266을 장착한 모듈, 8핀 소형 폼팩터, 보통 ESP-01 어댑터나 USB to TTL 변환 모듈을 통해 연결, 아두이노 IDE 등을 사용해 프로그램을 업로드하여 사용  

<H1>ESP-01 모듈과 컨버터 연결</H1>
<img width="1501" height="808" alt="image" src="https://github.com/user-attachments/assets/4d52ff32-43fd-475d-958a-3074fe5619b3" />
사진의 좌측은 ESP-01 모듈, 우측은 USB to TTL 컨버터  
* 펌웨어 업데이트 시에는 컨버터의 GND에 ESP-01의 IO0을 연결해놓은 상태여야 함, 펌웨어 업데이트 이후 연결선 제거
* USB 연결을 위해서는 PC에 드라이버 설치 필요

<H1>Arduino 보드와 ESP-01 모듈간 연결</H1>
같은 핀에 둘 이상의 연결이 필요한 경우가 있으므로 브레드보드 사용  
위에 첨부한 ESP-01 모듈의 핀 위치를 참고하여 아두이노 보드에 연결하면 되고,  
Arduino IDE의 SoftwareSerial esp8266(RX,TX); 이 코드를 작성할 때,  
RX 부분은 ESP-01의 TXD와 연결된 핀번호를,
TX 부분은 ESP-01의 RXD와 연결된 핀번호를 작성하면 된다.  
led의 +극은 저항과 함께 아무 핀 번호에 연결하면 되고, 첨부한 코드로 하려면 13번에 연결하면 된다.  

<H1>Wi-Fi 연결 및 IP 탐색</H1>
AT+CWMODE=1 명령어를 실행해 Wi-Fi 모드를 Station으로 변경하고,  
AT+CWLAP 명령어를 통해 연결 가능한 Wi-Fi를 찾으면 아래같이 뜬다.  
<img width="866" height="360" alt="image" src="https://github.com/user-attachments/assets/3599dc1d-9f0e-4356-93e1-46796bd57958" />

이후 AT+CWJAP="와이파이이름","와이파이비밀번호" 명령어를 입력하면(*공백없이입력)  
<img width="472" height="56" alt="image" src="https://github.com/user-attachments/assets/a2ab5239-bf5a-42a3-b3ba-1d29cccdc03d" />
이렇게 IP가 나온다.  
  
이 중 전자는 ESP-01 모듈 자체가 공유기 역할을 할 때 가질 고정 IP이고,  
후자는 ESP-01이 다른 Wi-Fi 공유기에 접속해서 부여받은 IP이다.  

이를 활용해서 HTML 코드의 IP 부분을 적절히 변경해서 사용할 수 있다.

<H3>HTML 실행화면</H3>  
참고로 HTML 실행화면은 아래와 같다.  
pin 13 이라고 적힌 버튼을 클릭하면 브레드보드에 연결된 led가 꺼진다.  
<img width="1538" height="412" alt="image" src="https://github.com/user-attachments/assets/a6ee1a79-cdda-4e16-a65d-1062af156249" />
