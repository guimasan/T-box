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

float temperature;
 

int lm35=A0;
int pot =A1;

int ledR=13;
int ledG=12;
int ledB=11;

int peltier=3;

void setup()
{
 
  pinMode(pot, INPUT);
  pinMode(lm35, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(peltier, OUTPUT);
  
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

