/*
LCD1602 (16*2).  The circuit 4bits:
 * LCD RS pin to digital pin PB11
 * LCD Enable pin to digital pin PB10
 * LCD D4 pin to digital pin PB0
 * LCD D5 pin to digital pin PB1
 * LCD D6 pin to digital pin PC13 (14)
 * LCD D7 pin to digital pin PC14 (15)
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/

#include <LiquidCrystal.h> // include the LCD library

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC14, d7 = PC15; //mention the pin names to with LCD is connected to 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Initialize the LCD

int potpin=1;// initialize analog pin 1
int val=0;// Temporarily store variables' value from the sensor
char buffer [16]; // a few bytes larger than your LCD line
int time, hour, min, sec;

void setup() {
  lcd.begin(16, 2);//We are using a 16*2 LCD
  lcd.setCursor(0, 0); //At first row first column 
  lcd.print("Voltmeter:"); //Print this
  lcd.setCursor(0, 1); //At secound row first column 
  lcd.print("..Starting..."); //Print this
  
  delay(3000); //wait for 3 secounds 
  lcd.clear(); //Clear the screen
}

void loop() {
  lcd.setCursor(0, 0); //At first row first column 
  time = millis();
  hour = time / 3600000;
  min = (time-hour*3600000) / 60000;
  sec = (time-hour*3600000-min*60000) / 1000;
  sprintf (buffer, "Measure %02d:%02d:%02d", hour, min, sec); // send data to the buffer
  lcd.print(buffer); //Print this

  lcd.setCursor(0, 1); //At second row first column 

  val=analogRead(potpin);// read the analog value from the sensor and assign it to val
  lcd.setCursor(0, 1); //At secound row first column 
  //lcd.print(millis() / 1000); //Print the value of secounds
  
  
  sprintf (buffer, "%5.3fV", float(val)*3.3/4096); // send data to the buffer
  lcd.print(buffer); 

//  lcd.print(float(val)*3.3/(4096-1)); 
//  lcd.print('V'); 
  
  delay(500); //wait for 0.5 secounds 
}

/*
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
// если на переходнике LCM1602
// запаяны A0 A1 A2 — адрес 0x20, не запаяны — 0x27.
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
//LiquidCrystal_I2C lcd(0x27); 
//LiquidCrystal_I2C lcd(0x27, 3, POSITIVE); 


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PB1 as an output.
  // 
  pinMode(PC13, OUTPUT);

//  
lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
  //lcd.backlight();//To Power ON the back light
  //
  lcd.print("Hi!");
  
}



// the loop function runs over and over again forever
void loop() {
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(4000);              // wait for a second


  //Write your code
  //
  lcd.home ();                   // go home
  //  
  lcd.setCursor(0,0); //Defining positon to write from first row,first column .
  lcd.print(" Tech Maker "); //You can write 16 Characters per line .
  delay(4000);//Delay used to give a dynamic effect
  //lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  //lcd.print("Like | Share");
  //delay(8000); 

  //
  lcd.clear();//Clean the screen
  //lcd.setCursor(0,0); 
  //lcd.print(" SUBSCRIBE ");
  //lcd.setCursor(0,1);
  //lcd.print(" TECH MAKER ");
  //delay(8000); 
}
*/
