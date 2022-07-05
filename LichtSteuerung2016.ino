//#include <Time.h>
unsigned long milli_(0);

unsigned long get_mil(){
  return milli_;
}

unsigned long mil(){
  return milli_++;
}

class Verbraucher{
  private:
  	short id=0;
  	bool on=false;
  	bool trigger=false;
  	short out=0;
    int max_time_ini=0;
    unsigned long time_switch_off=0;
  public:
  Verbraucher(int v_id, int ausgang, unsigned long max_time){
    out=ausgang;
    max_time_ini = max_time;
    id=v_id;
  }
  
  void Lampe(bool OnOff){
    if(time_switch_off < get_mil() && on){
      on=false;
      digitalWrite(out,false);
      Serial.print("Lampe auto aus id:");
      Serial.println(id);
      return;
    }
    if(trigger && OnOff){
      return;
    }else if(trigger && !OnOff){
      trigger=false;
      return;
    }else{
      if(OnOff){
        if(!on){
          on=true;
          time_switch_off = max_time_ini + get_mil();
          digitalWrite(out,true);
          Serial.print("Lampe ein id:");
    	  Serial.println(id);
        }else if(on){
          on=false;
          digitalWrite(out,false);
          Serial.print("Lampe aus id:");
	      Serial.println(id);
        }
	    trigger=true;
      }
    }
  }
};



// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led[] = {2,3,4,5,6,7,8,9};
int input[] = {10,11,12,13};
Verbraucher lampe1(101, led[0], 1000);
Verbraucher lampe2(102, led[1], 800);
Verbraucher lampe3(103, led[2], 800);
Verbraucher lampe4(104, led[3], 800);
Verbraucher lampe5(105, led[4], 800);
Verbraucher lampe6(106, led[5], 800);
Verbraucher lampe7(107, led[6], 800);
Verbraucher lampe8(108, led[7], 800);
Verbraucher lampe9(109, led[7], 800);
Verbraucher lampe10(110, led[7], 800);
Verbraucher lampe11(111, led[7], 800);
Verbraucher lampe12(112, led[7], 800);
Verbraucher lampe13(113, led[7], 800);
Verbraucher lampe14(114, led[7], 800);
Verbraucher lampe15(115, led[7], 800);
Verbraucher lampe16(116, led[7], 800);


// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait until Arduino Serial Monitor opens
  Serial.println("Start input");
  
  for(int i=0; i<3;i++){
  	pinMode(input[i], INPUT);
    Serial.println(i);
   
  }
  // initialize the digital pin as an output.
  Serial.println("Start output");
  for(int i=0; i<3;i++){
  	pinMode(led[i], OUTPUT);
    Serial.println(i);
  }
  Serial.println("End init");
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = mil();
  
//  for(int i=0; i<3;i++){
// 	 digitalWrite(led[i],digitalRead(input[i]));   // turn the LED on (HIGH is the voltage level)
//   	Serial.print("input:");
//   	Serial.println(digitalRead(input[i]));
//  }

  lampe1.Lampe(digitalRead(input[0]));
  lampe2.Lampe(digitalRead(input[1]));
  lampe3.Lampe(digitalRead(input[2]));
  lampe4.Lampe(digitalRead(input[3]));
  lampe5.Lampe(digitalRead(input[1]));
  lampe6.Lampe(digitalRead(input[1]));
  lampe7.Lampe(digitalRead(input[1]));
  lampe8.Lampe(digitalRead(input[1]));
  lampe9.Lampe(digitalRead(input[1]));
  lampe10.Lampe(digitalRead(input[1]));
  lampe11.Lampe(digitalRead(input[1]));
  lampe12.Lampe(digitalRead(input[1]));
  lampe13.Lampe(digitalRead(input[1]));
  lampe14.Lampe(digitalRead(input[1]));
  lampe15.Lampe(digitalRead(input[1]));
  lampe16.Lampe(digitalRead(input[1]));
   
  delay(20);               // wait for a second
//  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);               // wait for a second
}
