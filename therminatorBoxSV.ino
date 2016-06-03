/*
* Therminator Box
* [Thermal arduino incubator Box]

* GSan
* --
* GypsyLab AT - @gypsylab85
* gypsylabat.wordpress.com
*
*/
 
#define TEMP 37 

int a,b,c;
float temperature;
int B=3975;                  //B value of the thermistor
float resistance;
 
int peltier=3;
int lm35=A0;
int pot =A1;
int ledR=13;
int ledG=12;
int ledB=11;

void setup()
{
  pinMode(peltier, OUTPUT);
  pinMode(lm35, INPUT);
  pinMode(pot, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  
    // initialize the serial communications:
    Serial.begin(9600);
    
}

void loop()
{
 
temperature=(float(analogRead(lm35))*5/(1023))/0.01;
    
      Serial.print("Temp:");
      Serial.print(temperature);
      Serial.print("Temp:");
      Serial.println(TEMP);
      
      if(temperature < TEMP){
       analogWrite(peltier, 500+b/2);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledR, LOW);
      
      } else if(temperature=TEMP){
        digitalWrite(ledG, HIGH);
        digitalWrite(ledB, LOW);
        digitalWrite(ledR, LOW);
      } else {
        analogWrite(peltier,0);
        digitalWrite(ledG, LOW);
        digitalWrite(ledB, LOW);
        digitalWrite(ledR, HIGH);
      }
      
          
}

