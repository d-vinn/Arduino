초음파를 이용해 거리를 측정하는 센서  
트리거(Trig) 핀으로 초음파 신호를 보내고,  
물체에 반사되어 돌아오는 시간을 에코(Echo) 핀에서 측정해 거리 계산  
*로봇의 장애물 감지, 주차 센서 등 다양한 프로젝트에 활용  

<img width="450" height="560" alt="image" src="https://github.com/user-attachments/assets/17e3efc5-5468-447a-9867-ebc85b0378ef" />
핀 순서는 전원, 트리거, 에코, 접지  


접지는 아두이노 보드의 GND,  
전원은 아두이노 보드의 5V,  
트리거와 에코는 아두이노 보드의 숫자 핀에 연결하면 된다.  
*참고로, #define TRIG_PIN 6 #define ECHO_PIN 7 명령어를 사용할 것이라면 트리거는 6, 에코는 7에 연결하면 된다.  
