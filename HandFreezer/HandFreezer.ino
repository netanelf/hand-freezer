
#define data_in  A2
#define clk  A1
#define load A0

#define SENSORS_NUM  8

#define SENSOR_0 6
#define SENSOR_1 7

#define LED_0 4
#define LED_1 5

#define FLASH_TIME 1
#define TIME_BETWEEN_SAMPLES 10    // [mS]

int activeSensor = SENSOR_0;
int sensorState[SENSORS_NUM];

void setup(){
  Serial.begin(9600);
 
  pinMode(data_in, INPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
    
  digitalWrite(load, HIGH);
  digitalWrite(clk, HIGH);
}

void loop(){
   readData();
   checkData();
   delay(TIME_BETWEEN_SAMPLES);
}


void readData(){
      digitalWrite(load, LOW);
      digitalWrite(load, HIGH);
      for(int i=0; i<SENSORS_NUM; i++){
            sensorState[i] = digitalRead(data_in);
            digitalWrite(clk, LOW);
            digitalWrite(clk, HIGH);
    }
}

void checkData(){
  if      (activeSensor == SENSOR_0 && sensorState[SENSOR_0]){
    flashLed(LED_0, FLASH_TIME);
    activeSensor = SENSOR_1;
  }
  else if (activeSensor == SENSOR_1 && sensorState[SENSOR_1]){
    flashLed(LED_1, FLASH_TIME);
    activeSensor = SENSOR_0;    
  }
}

void flashLed(int led, int t){
  digitalWrite(led, HIGH);
  delay(t);
  digitalWrite(led, LOW);
}



