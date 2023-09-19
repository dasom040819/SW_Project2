#define PIN_LED 7
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  Serial.println("Hello World!");
  count = 0;
  toggle = 0;
  digitalWrite(PIN_LED, toggle);
}

void loop() {
  delay(1000);
  while(1){
    while(count<=10){
      count+=1;
      Serial.println(count);
      toggle = toggle_state(toggle, count);
      digitalWrite(PIN_LED, toggle);
      delay(100);
     }
    digitalWrite(PIN_LED, 1);
  }
}

int toggle_state(int toggle, int count){
  return !toggle;
}
