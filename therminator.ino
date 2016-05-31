/*
* Therminator Box
* [Thermal arduino incubator Box]

* GSan
* --
* GypsyLab AT - @gypsylab85
* gypsylabat.wordpress.com
*
*  Grove modules (seeedstudio): Temperature and LDC Display RGB codes.
* https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight/archive/master.zip
*  By: http://www.seeedstudio.com
*/
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int a,b,c;
float temperature;
int B=3975;                  //B value of the thermistor
float resistance;
 
int peltier=3;
int lm35=A0;
int pot =A1;

void setup()
{
  pinMode(peltier, OUTPUT);
  pinMode(lm35, INPUT);
  pinMode(pot, INPUT);
  
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // initialize the serial communications:
    Serial.begin(9600);
    
}

void loop()
{
 
  a=analogRead(lm35);
      resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
      temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet ;

    //  temperature=(float(analogRead(lm35))*5/(1023))/0.01;
    

//int temp = analogRead(lm35);
//temperature = temp * 0.48828125;

int potRead =analogRead(pot);
      int potX=map(potRead, 0, 1023, -55, 150); 
      
      
       
      
      Serial.print("Temp:");
      Serial.print(temperature);
      Serial.print("Temp:");
      Serial.println(potX);
      
      if(temperature < potX){
       analogWrite(peltier, 500+b/2); 
      } else {
        analogWrite(peltier,0);
      }
      

  // display each character to the LCD
  lcd.print("Now :");lcd.print(temperature);lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Set Temp.:");lcd.print(potX);lcd.print("C");
  // wait a bit for the entire message to arrive
  delay(100);
  // clear the screen
 lcd.clear();
          
}
