
#define data_in  A2
#define clk  A1
#define load A0

#define SENSORS_NUM  8

#define TIME_BETWEEN_SAMPLES 100    // [mS]

void setup(){
  Serial.begin(9600);
 
  pinMode(data_in, INPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
    
  digitalWrite(load, HIGH);
  digitalWrite(clk, HIGH);
}

void loop(){
   readData();
   delay(1000);
}


void readData(){
      digitalWrite(load, LOW);
      delay(50);
      digitalWrite(load, HIGH);
      Serial.println("---------");
      for(int i=0; i<SENSORS_NUM; i++){
            int d = digitalRead(data_in);
            Serial.println(d);
            digitalWrite(clk, LOW);
            delay(5);
            digitalWrite(clk, HIGH);
    }
}



