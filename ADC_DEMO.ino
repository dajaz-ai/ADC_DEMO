/*========================================
ADC_DEMO


ARAGON, EDWARD PAUL M.
REGALADO, CID LAWRENC C. 
==========================================
------------------------------------------*/
//GPIO
const uint8_t POT = 36;
const int LED[] = {26,33,25};
//variable
int pot_val =0;
const int FREQ   = 5000;
const uint8_t RES    = 12;
const int level1 =1365;
const int level2 =2030;
const int level3 = 4095;
void setup() {
  // ADC pin
  pinMode(POT,INPUT);
  ledcAttach(LED[0],FREQ,RES);
  ledcAttach(LED[1],FREQ,RES);
  ledcAttach(LED[2],FREQ,RES);
 
  Serial.begin(9600);
}

void loop() {
pot_val = analogRead(POT);
if(pot_val <= level1){
ledcWrite(LED[0],level3);
ledcWrite(LED[1],0);
ledcWrite(LED[2],0);
delay(500);
Serial.println("Brightness: Level 1");
}
else if(pot_val <= level2){
ledcWrite(LED[0],0);
ledcWrite(LED[1],level3);
ledcWrite(LED[2],0);
delay(500);
Serial.println("Brightness: Level 2");

}
else{
ledcWrite(LED[0],0);
ledcWrite(LED[1],0);
ledcWrite(LED[2],level3);
delay(500);
Serial.println("Brightness: Level 3");
}

}
