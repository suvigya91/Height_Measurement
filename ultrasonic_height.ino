#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int inputPin=9;  // connect digital I/O 4 to the ECHO/Rx Pin
int outputPin=8; // connect digital I/O 5 to the TRIG/TX Pin
int buzzer=10;
int i=0;
static float ref;
void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);

  
}
void loop()
{
     /*  
      digitalWrite(outputPin, LOW);  // send low pulse for 2μs
      delayMicroseconds(2);
      digitalWrite(outputPin, HIGH); // send high pulse for 10μs
      delayMicroseconds(10);
      digitalWrite(outputPin, LOW);  // back to low pulse
      int ref_raw = pulseIn(inputPin, HIGH);  // read echo value
      int ref= ref_raw/29/2;  // in cm
      int sub = ref;
      Serial.println("ref=");
      Serial.println(ref);*/
  
   digitalWrite(outputPin, LOW);  // send low pulse for 2μs
   delayMicroseconds(2);
   digitalWrite(outputPin, HIGH); // send high pulse for 10μs
   delayMicroseconds(10);
   digitalWrite(outputPin, LOW);  // back to low pulse
   int distance = pulseIn(inputPin, HIGH);  // read echo value
   float distance1= distance/29/2;  // in cm
   float distance2= (0.0328084)*(distance1);
   if(i < 2)
   {
     ref = distance2;
     lcd.print("Ref height in cms.....");
     lcd.setCursor(0,1);
     lcd.print(ref);
     delay(300);
     lcd.clear();
     i++; 
   }
   
   Serial.println("dist=");
   Serial.println(distance2);
   float height = ref - distance2;
   
   Serial.println(height);
   lcd.print(height);
   delay(300);
   lcd.clear();
  // if(distance1 < 30)
  //{
  //   digitalWrite(buzzer, HIGH);
  //} 
  
  //else
  //{
  //   digitalWrite(buzzer, LOW); 
  //}
  
   //delay(100);  
}
