#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


void blink(int frequency){

    
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
  
  Write a program that blinks S-O-S morse code when uses presses the button. The code is: dot, dot,
dot, dash, dash, dash, dot, dot, dot, (long pause if code repeats). The length of dash is three times
the lengt of a dot. The off time between dots and dashes is one dot long. For example, if dot lenght
is 0.5 seconds the sequence is 0.5s ON, 0,5 s OFF, 0,5 ON, 0,5 s OFF, 0.5 s ON, 0.5 s OFF, 1.5 ON, 0.5 s
OFF, 1.5 s ON, …
After the sequence the program goes back to wait for another button press to start S-O-S again.

 */

    
void zmain(void)
{
    printf("\nBoot\n");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 
    
    //uint8 button;
    //button = SW1_Read(); // read SW1 on pSoC board
    // SW1_Read() returns zero when button is pressed
    // SW1_Read() returns one when button is not pressed
    
    bool led = false;
    
    for(;;)
    {
        // toggle led state when button is pressed
        
        if(SW1_Read() == 0) {    // == 0, means its already paused
            
            led = !led;
            if(led == true ) ;
            BatteryLed_Write(led);    //check if the function should be true
}
            
      
            
void S()
{
            BatteryLed_Write(50);        // S = dot / dot / dot
            vTaskDelay(50);   
            BatteryLed_Write(50)        
            vTaskDelay(50);
            BatteryLed_Write(50);
            vTaskDelay(100);
    
            //The length of dash is three times the lengt of a dot.
            
            //between letter and letter, one dot time as gap
            BatteryLed_Write(50);
}
            
void O()
{
            vTaskDelay(100);             // o = dash / dash / dash
            BatteryLed_Write(150);
            vTaskDelay(50);   
            BatteryLed_Write(150);       
            vTaskDelay(50); 
            BatteryLed_Write(150);   
            vTaskDelay(100);
    
            //here, one dot time as gap
            BatteryLed_Write(50);
}
              
            
            if
            { (SW1_Read() == 0)  // wait while button is being pressed
                S & O & S();
             
             }
    
        
    return 0;
 
 }  
