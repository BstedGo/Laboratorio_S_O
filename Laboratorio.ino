int const LED1 = 11;
int const LED2 = 12;
int const LED3 = 13;
char opt;
void setup() { 
Serial.begin(9600);//9600_baudios
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  
  Serial.println("Menu, please choose some option");
  Serial.println("opt = 1, turn on LED RED");
  Serial.println("opt = 2, turn off LED RED");
  Serial.println("opt = 3, turn on LED YELLOW");
  Serial.println("opt = 4, turn off LED YELLOW");
  Serial.println("opt = 5, turn on LED GREEN");
  Serial.println("opt = 6, turn off LED GREEN");
  Serial.println("opt = 7, Turn on all");
  Serial.println("opt = 8, Turn off all");
  Serial.println("opt = 9, intermitence");
}

void loop() {
  if (Serial.available() > 0) {
   opt = Serial.read();
    processOpt:
  switch (opt){
    case '0':
        if (digitalRead(LED1) == HIGH) {
          Serial.println("Toggle: Turn off LED1");
          digitalWrite(LED1, LOW);
        } else {
          Serial.println("Toggle: Turn on LED1");
          digitalWrite(LED1, HIGH);
        }
        break;
   case '1':
    Serial.println("Turn on LED1");
    digitalWrite(LED1, HIGH);
    break;
    case '2':
    Serial.println("Turn off LED1");
    digitalWrite(LED1, LOW);
    break;
    case '3':
    Serial.println("Turn on LED2");
    digitalWrite(LED2, HIGH);
    break;
    case '4':
    Serial.println("Turn off LED2");
    digitalWrite(LED2, LOW);
    break;
    case '5':
    Serial.println("Turn on LED3");
    digitalWrite(LED3, HIGH);
    break;
    case '6':
    Serial.println("Turn off LED3");
    digitalWrite(LED3, LOW);
    break;
    case '7':
    digitalWrite(LED3, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    break;
    case '8':
    digitalWrite(LED3, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    break;
    case '9':
    do  {
    if (Serial.available() > 0) {
      opt = Serial.read();
      goto processOpt;
    }
      digitalWrite(LED3, HIGH);
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      delay(300);
      digitalWrite(LED3, LOW);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      delay(300);
      }while (opt == '9');
    }
 }
  
}






