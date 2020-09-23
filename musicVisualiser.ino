void setup() {
   pinMode(A0,INPUT); // к аналоговому входу A0 подключим датчик (англ. «intput»)
   Serial.begin(9600); // подключаем монитор порта
}

void loop() {
   Serial.println (analogRead(A0)); // выводим значение датчика на монитор
  
}