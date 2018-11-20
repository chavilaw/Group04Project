/**
* @mainpage ZumoBot Project
* @brief    You can make your own ZumoBot with various sensors.
* @details  <br><br>
    <p>
    <B>General</B><br>
    You will use Pololu Zumo Shields for your robot project with CY8CKIT-059(PSoC 5LP) from Cypress semiconductor.This 
    library has basic methods of various sensors and communications so that you can make what you want with them. <br> 
    <br><br>
    </p>
    
    <p>
    <B>Sensors</B><br>
    &nbsp;Included: <br>
        &nbsp;&nbsp;&nbsp;&nbsp;LSM303D: Accelerometer & Magnetometer<br>
        &nbsp;&nbsp;&nbsp;&nbsp;L3GD20H: Gyroscope<br>
        &nbsp;&nbsp;&nbsp;&nbsp;Reflectance sensor<br>
        &nbsp;&nbsp;&nbsp;&nbsp;Motors
    &nbsp;Wii nunchuck<br>
    &nbsp;TSOP-2236: IR Receiver<br>
    &nbsp;HC-SR04: Ultrasonic sensor<br>
    &nbsp;APDS-9301: Ambient light sensor<br>
    &nbsp;IR LED <br><br><br>
    </p>
    
    <p>
    <B>Communication</B><br>
    I2C, UART, Serial<br>
    </p>
*/

#include <project.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Motor.h"
#include "Ultra.h"
#include "Nunchuk.h"
#include "Reflectance.h"
#include "Gyro.h"
#include "Accel_magnet.h"
#include "LSM303D.h"
#include "IR.h"
#include "Beep.h"
#include "mqtt_sender.h"
#include <time.h>
#include <sys/time.h>
#include "serial1.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * @file    main.c
 * @brief   
 * @details  ** Enable global interrupt since Zumo library uses interrupts. **<br>&nbsp;&nbsp;&nbsp;CyGlobalIntEnable;<br>
*/


#if 0
// Hello World!
void zmain(void)
{
    printf("\nHello, World!\n");

    while(true)
    {
        vTaskDelay(100); // sleep (in an infinite loop)
    }
 }   
#endif

#if 0
// Name and age made by melinda varo
void zmain(void)
{
   // char name[32];
    int age;
    TickType_t first_time, last_time, execution_time;
	 
    
    //printf("\n\n");
    
   // printf("Enter your name: ");
    //fflush(stdout);
   // scanf("%s", name);
   
    printf("Enter your age: \n");
    //fflush(stdout);
	first_time = xTaskGetTickCount( );
	scanf("%d", &age);
	last_time=xTaskGetTickCount( );
		
	execution_time=last_time - first_time;
			  
	if (age<=21)
	{
		if (execution_time <= 3000)
			printf("Super fast dude!\n");
					 
		else if (execution_time > 3000 && execution_time <= 5000 )
			printf("So mediocre\n");
					 
		else
			printf("My granny is faster than you!\n");
		
	}
	 
    else if ( (age > 21) && (age <= 50))
	{
		if (execution_time <= 3000)
			printf("Be quick or be dead\n");
					 
		else if (execution_time > 3000 && execution_time <= 5000)
			printf("You\'re so average.\n");
					 
		else
			printf("Have you been smoking something illegal?\n");
	}
   
	else 
	{
		if (execution_time <= 3000)
		    printf("Still going strong\n");
		
		else if (execution_time > 3000 && execution_time <=5000 )
			printf("You are doing ok for your age.\n");
			 
		else
			printf("Do they still allow you to drive?\n");
			
	}
    //printf("You are [%s], age = %d\n", name, age);
    while(1)
    {
    }
    /*while(true)
    {
        BatteryLed_Write(!SW1_Read());
        vTaskDelay(100);
    }*/
 }   
#endif

#if 0
//battery level made by eliza
void measure_battery();
void warning_cycle();
bool condition=false;
uint8_t button;
int16 value;
int16 adcresult;
float  value_scaled, volt;

void zmain(void)
{
    ADC_Battery_Start();   
    ADC_Battery_StartConvert();
    
    printf("\nBoot\n");
    //BatteryLed_Write(1); // Switch led on 
    //BatteryLed_Write(0); // Switch led off 
    //button = SW1_Read();// read SW1 on pSoC board    
    //uint8_t button;
    //BatteryLed_Write(0);    
    // SW1_Read() returns zero when button is pressed
    // SW1_Read() returns one when button is not pressed
    //for(;;)
	while(1)
	{
		if(condition==false)
			measure_battery();
		else if (condition == true)
			warning_cycle();
	}
}  
void measure_battery()
{
	value_scaled = ( value *5.0 ) / 4095; // convert value to Volts
	volt =  value_scaled * 3 /2;
	while (condition == false)
    {
        ADC_Battery_IsEndConversion(ADC_Battery_WAIT_FOR_RESULT);
        value = ADC_Battery_GetResult16(); // get the ADC value (0 - 4095)
        float value_scaled = ( value *5.0 ) / 4095; // convert value to Volts
	    volt =  value_scaled * 3 /2;
        printf("%d %f\r\n", value, volt);
		if (volt <= 4.0)
        {
			condition=true; 
        }
        vTaskDelay(500);
    }
}

void warning_cycle()
{
    while (condition==true)
    {
		BatteryLed_Write(1);
        vTaskDelay(500);
        BatteryLed_Write(0);
        vTaskDelay(500);
		if (SW1_Read() == 0)
		{	
			condition=false;
        }
    }
}
#endif
    


#if 0
// button
void zmain(void)
{
    while(1) {
        printf("Press button within 5 seconds!\n");
        int i = 50;
        while(i > 0) {
            if(SW1_Read() == 0) {
                break;
            }
            vTaskDelay(100);
            --i;
        }
        if(i > 0) {
            printf("Good work\n");
            while(SW1_Read() == 0) vTaskDelay(10); // wait until button is released
        }
        else {
            printf("You didn't press the button\n");
        }
    }
}
#endif

#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define F_CPU 16000000
//#include <avr/io.h>
//#include <util/delay.h>


//void blink(){

    
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

void blink_S();
void blink_O();
 
void zmain(void)
{
    printf("\nBoot\n");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 
    
    //uint8 button;
    //button = SW1_Read(); // read SW1 on pSoC board
    // SW1_Read() returns zero when button is pressed
    // SW1_Read() returns one when button is not pressed
    
    //bool led = false;
    
    for(;;)
    {
        // toggle led state when button is pressed
        
        /* if(SW1_Read() == 0) 
		{    // == 0, means its already paused
            
            //led = !led;
            if(led == true )
				BatteryLed_Write(led);    //check if the function should be true
		} */
		if(SW1_Read() == 0)  // wait while button is being pressed
            {
				blink_S();
                blink_O();
                blink_S();
             
            }
        else
			BatteryLed_Write(0);
    } 
            

              
            
           
}
void blink_S()
	{
            BatteryLed_Write(1);        // S = dot / dot / dot
            vTaskDelay(500); 
			BatteryLed_Write(0);
            vTaskDelay(500); 
            BatteryLed_Write(1);       
            vTaskDelay(500);
			BatteryLed_Write(0);
            vTaskDelay(500); 
            BatteryLed_Write(1);
            vTaskDelay(500);
            BatteryLed_Write(0);
			vTaskDelay(500);
            
            //The length of dash is three times the lengt of a dot.
            //between letter and letter, one dot time as gap
            
	}
            
void blink_O()
	{
            //vTaskDelay(100);             // o = dash / dash / dash
            BatteryLed_Write(1);
            vTaskDelay(1500);
			BatteryLed_Write(0);
            vTaskDelay(1500);
            BatteryLed_Write(1);       
            vTaskDelay(1500);
			BatteryLed_Write(0);
            vTaskDelay(1500);
            BatteryLed_Write(1);   
            vTaskDelay(1500);
            BatteryLed_Write(0);
            vTaskDelay(1500);
			
    
            //here, one dot time as gap
			//BatteryLed_Write(0);
            //vTaskDelay(500);
	}

#endif


#if 0
//ultrasonic sensor//

int motorVelocity = 60;
void beep_reverse();
int d = 0; // Print the detected distance (centimeters)
    
void zmain(void)
{
    Ultra_Start();              // Ultra Sonic Start function
    //if (SW1_Read() == 0)
    //{
    motor_start();              // enable motor controller
    motor_forward(0,0);     // moving forward
    
    vTaskDelay(500);
    //}
    
   // else
   //motor_forward(0,0);

for(;;)
{
    
    while(1) {
        
        d = Ultra_GetDistance(); // Print the detected distance (centimeters)
    
        if(d <= 10) // if the distance is less than 10 cm
        
         {
            motor_forward(0,0);         // set speed to zero to stop motor
            vTaskDelay(500);
            beep_reverse();
            vTaskDelay(100);
          }
        
        else // if the distance is moore than 10 cm
        
         {
            motor_forward(100,0);         // set speed to zero to stop motor
            vTaskDelay(0);
         }
    }
        
     vTaskDelay(10);
}
}
        

void beep_reverse()
{
   Beep(1000,150);    // moving backward
            
  motor_backward(100,2000); //turn first
  motor_turn(100,25,250);
        //while motor_backward(100,2000);     // turn & move backward
        vTaskDelay(1000);
 }

#endif


#if 0
//IR receiverm - how to wait for IR remote commands
void zmain(void)
{
    IR_Start();
    
    printf("\n\nIR test\n");
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    bool led = false;
    // Toggle led when IR signal is received
    for(;;)
    {
        IR_wait();  // wait for IR command
        led = !led;
        BatteryLed_Write(led);
        if(led) printf("Led is ON\n");
        else printf("Led is OFF\n");
    }    
 }   
#endif



#if 0
//IR receiver - read raw data
void zmain(void)
{
    IR_Start();
    
    uint32_t IR_val; 
    
    printf("\n\nIR test\n");
    
    IR_flush(); // clear IR receive buffer
    printf("Buffer cleared\n");
    
    // print received IR pulses and their lengths
    for(;;)
    {
        if(IR_get(&IR_val, portMAX_DELAY)) {
            int l = IR_val & IR_SIGNAL_MASK; // get pulse length
            int b = 0;
            if((IR_val & IR_SIGNAL_HIGH) != 0) b = 1; // get pulse state (0/1)
            printf("%d %d\r\n",b, l);
        }
    }    
 }   
#endif


#if 0
//reflectance
void zmain(void)
{
    struct sensors_ ref;
    struct sensors_ dig;

    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
    

    for(;;)
    {
        // read raw sensor values
        reflectance_read(&ref);
        // print out each period of reflectance sensors
        printf("%5d %5d %5d %5d %5d %5d\r\n", ref.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);       
        
        // read digital values that are based on threshold. 0 = white, 1 = black
        // when blackness value is over threshold the sensors reads 1, otherwise 0
        reflectance_digital(&dig); 
        //print out 0 or 1 according to results of reflectance period
        printf("%5d %5d %5d %5d %5d %5d \r\n", dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);        
        
        vTaskDelay(200);
    }
}   
#endif


#if 0
//motor
void zmain(void)
{
    motor_start();              // enable motor controller
    motor_forward(0,0);         // set speed to zero to stop motors

    vTaskDelay(3000);
    
    motor_forward(100,2000);     // moving forward, milisecond delay how long motor is on
    motor_turn(200,50,2000);     // turn
    motor_turn(50,200,2000);     // turn
    motor_backward(100,2000);    // moving backward
     
    motor_forward(0,0);         // stop motors 

    motor_stop();               // disable motor controller, full stop need start again to go
    
    for(;;)
    {

    }
}
#endif

#if 0
//motor
void straight_line();
void tankturn_right();
uint8 speed;
uint32 delay;
uint8 f_speed;
uint8 b_speed;

void zmain(void)
{
	motor_start();
	motor_forward(0,0);
    /*motor_start();              // enable motor controller
    motor_forward(0,0);         // set speed to zero to stop motors

    vTaskDelay(3000);
    
    motor_forward(100,2000);     // moving forward, milisecond delay how long motor is on
    motor_turn(200,50,2000);     // turn
    motor_turn(50,200,2000);     // turn
    motor_backward(100,2000);    // moving backward
     
    motor_forward(0,0);         // stop motors 

    motor_stop();               // disable motor controller, full stop need start again to go
    */
    while(1)
    {
//step 1
	if (SW1_Read() == 0)
		{
		vTaskDelay(500);

//step 2
		motor_forward(150,2200);
        motor_forward(0,0);

//step 3
        
		tankturn_right(150,150,250);
        motor_forward(0,0);
//step 4
		motor_forward(150,1800);
        motor_forward(0,0);
//step 5
		tankturn_right(150,150,260);
        motor_forward(0,0);
//step 6
		motor_forward(150,2000);
        motor_forward(0,0);
//step 7 
        tankturn_right(150,150,250);
        motor_forward(0,0);
		motor_turn(150,90,2200);
        motor_forward(0,0);
        motor_forward(150,550);
        
//step 8
		motor_forward(0,0);
	}
	else
		motor_forward(0,0); 
    }
}
/*void straight_line()
{
    
    MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(0);     // set RightMotor forward mode
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    vTaskDelay(delay);

}
*/

void tankturn_right(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}
#endif

#if 0
/* Example of how to use te Accelerometer!!!*/
void random_reverse();
void tankturn_right();
void tankturn_left();
uint8_t speed;
uint32_t delay;
uint8_t f_speed;
uint8_t b_speed;
void zmain(void)
{
    struct accData_ data;
    int i=0;
    int n=0;
    
    printf("Accelerometer test...\n");

    if(!LSM303D_Start())
    {
        printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
        vTaskSuspend(NULL);
    }
    else 
    {
        printf("Device Ok...\n");
    }

	motor_start();              // enable motor controller
    motor_forward(0,0);    		// moving forward
    vTaskDelay(500);
while(1)
{
	
    
	switch(n)
	{

	case 0:
        {
		LSM303D_Read_Acc(&data);
		print_mqtt("Zumo006/debug","Case 0 value n: %d value i: %d", n, i);
        if(data.accX < -2000)
        {
            n= 3;
            print_mqtt("Zumo006/debug","Hit in Case 0 value n: %d", n);
            break;
        }
		else if((i<30) && (data.accX > -2000))
	        { 
	        LSM303D_Read_Acc(&data);
            motor_forward(150,1);
	        i++;
            print_mqtt("Zumo006/debug","Forward in Case 0 value n: %d value i: %d", n, i);
            n=n;
            } 
		else
            {
           n = rand()%3;
           break;}
            }
        break;
	case 1:
        {
		tankturn_right(100,100,250);
        i=0;
        print_mqtt("Zumo006/debug","Case 1 value n: %d", n);
        n = rand()%3;
        break;
        }
	case 2:
        {
		tankturn_left(100,100,250);
        i=0;
	    print_mqtt("Zumo006/debug","Case 2 value n: %d", n);
        n = rand()%3;
		break;
        }
	case 3:
        {
		random_reverse();
        print_mqtt("Zumo006/debug","Case 3 value n: %d", n);
		i=0;
		n=0;
		break;
        }

	}  
} 
}
        
void tankturn_right(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}
void tankturn_left(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(0);     // set RightMotor forward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
    
}
void random_reverse()
{    
  
  motor_backward(100,1000); // moving backward
  int n = rand() %2;
  if (n == 0)
  {
  	tankturn_left(100,25,250);//turn first 
  //vTaskDelay(1000);
    }
  else 
  	{
  	tankturn_right(25,100,250);
    //vTaskDelay(1000);
	}
 } 
#endif    

#if 0
// MQTT test
void zmain(void)
{
    int ctr = 0;

    printf("\nBoot\n");
    send_mqtt("Zumo01/debug", "Boot");

    //BatteryLed_Write(1); // Switch led on 
    BatteryLed_Write(0); // Switch led off 

    for(;;)
    {
        printf("Ctr: %d, Button: %d\n", ctr, SW1_Read());
        print_mqtt("Zumo01/debug", "Ctr: %d, Button: %d", ctr, SW1_Read());

        vTaskDelay(1000);
        ctr++;
    }
 }   
#endif


#if 0
void zmain(void)
{    
    struct accData_ data;
    struct sensors_ ref;
    struct sensors_ dig;
    
    printf("MQTT and sensor test...\n");

    if(!LSM303D_Start()){
        printf("LSM303D failed to initialize!!! Program is Ending!!!\n");
        vTaskSuspend(NULL);
    }
    else {
        printf("Accelerometer Ok...\n");
    }
    
    int ctr = 0;
    reflectance_start();
    for(;;)
    {
        LSM303D_Read_Acc(&data);
        // send data when we detect a hit and at 10 second intervals
        //if(data.accX > 1500 || ++ctr > 1000) {
            //printf("Acc: %8d %8d %8d\n",data.accX, data.accY, data.accZ);
            //print_mqtt("Zumo006/acc", "%d,%d,%d", data.accX, data.accY, data.accZ);
            //reflectance_read(&ref);
            //printf("Ref: %8d %8d %8d %8d %8d %8d\n", ref.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);       
            //print_mqtt("Zumo006/ref", "%d,%d,%d,%d,%d,%d", ref.l3, ref.l2, ref.l1, ref.r1, ref.r2, ref.r3);
            reflectance_digital(&dig);
            printf("Dig: %8d %8d %8d %8d %8d %8d\n", dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);
            print_mqtt("Zumo006/dig", "%d,%d,%d,%d,%d,%d", dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);
            ctr = 0;
        //}
        vTaskDelay(10);
    }
 }   

#endif

#if 0
void zmain(void)
{    
    RTC_Start(); // start real time clock
    
    RTC_TIME_DATE now;

    // set current time
    now.Hour = 12;
    now.Min = 34;
    now.Sec = 56;
    now.DayOfMonth = 25;
    now.Month = 9;
    now.Year = 2018;
    RTC_WriteTime(&now); // write the time to real time clock

    for(;;)
    {
        if(SW1_Read() == 0) {
            // read the current time
            RTC_DisableInt(); /* Disable Interrupt of RTC Component */
            now = *RTC_ReadTime(); /* copy the current time to a local variable */
            RTC_EnableInt(); /* Enable Interrupt of RTC Component */

            // print the current time
            printf("%2d:%02d.%02d\n", now.Hour, now.Min, now.Sec);
            
            // wait until button is released
            while(SW1_Read() == 0) vTaskDelay(50);
        }
        vTaskDelay(50);
    }
 }   
#endif


#if 0
//ultrasonic sensor//

int motorVelocity = 60;
int d = 0;

void zmain(void)
{
    Ultra_Start();              // Ultra Sonic Start function
    
    motor_start();              // enable motor controller
    motor_forward(0,0);     // moving forward
    
    vTaskDelay(500);
    


for(;;)
{
    
    while(1) {
        d = Ultra_GetDistance(); // Print the detected distance (centimeters)
        
        
        if(d = > 10) // if the distance is less than 10 cm
        
         {
            motor_forward(0,0);         // set speed to zero to stop motor
            vTaskDelay(500);
            command();
            vTaskDelay(500);
            --d;
         }
        
        else // if the distance is moore than 10 cm
        
         {
            motor_forward(100,0);         // set speed to zero to stop motor
            vTaskDelay(0);
         }
    }
        
     vTaskDelay(10);
}
}
        

void command();
 {
   Beep(1000, 150);    // moving backward
            
   motor_backward(100,2000); //turn first
        
   motor_turn(200,50,2000)
    vTaskDelay(100);

 }
    
    
    


#endif

#if 0
    // Assignment 3 week 4
void Go_Stop (void);
struct sensors_ dig;
void Follow_Line_Stop(void);
void tankturn_right();
void tankturn_left();


void zmain(void)
{
reflectance_start();
reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000

// void IR_wait(void); //wait for any IR 

for(;;)
    {
        // read digital values that are based on threshold. 0 = white, 1 = black
        reflectance_digital(&dig); 
        printf("DIG l3:%d. l2:%d. l1:%d. r1:%d. r2:%d. r3:%d.\n", dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);         
        vTaskDelay(0);
    if (SW1_Read()== 0)// button press
    {
        Go_Stop();
        IR_Start(); // start IR receiving
        IR_flush(); // clear IR receive buffer
   		IR_wait();
   		Follow_Line_Stop();
    }
    else
        motor_forward(0,0);

    }
}

void Go_Stop (void)
{
   
	motor_start();
	motor_forward(0,0);
    
while (1)
{
    reflectance_digital(&dig);
while ((dig.l3 == 0) && (dig.r3 == 0))
   {
    motor_forward(100,0);
    reflectance_digital(&dig);
    }
if ((dig.l3 == 1) && (dig.r3 == 1))
    {
    motor_forward(0,0);
    reflectance_digital(&dig);
    break;
    }
}
}

void Follow_Line_Stop(void)
{
	while (1)
	{
		reflectance_digital(&dig);
		if ((dig.l1 == 1) && (dig.r1 == 1))
		{
			motor_forward(150,0);
			reflectance_digital(&dig);
		}
		else if ((dig.l1 == 0) && (dig.r1 == 1))
		{
		tankturn_right(10,50,0);
		reflectance_digital(&dig);
		}
		else if ((dig.l1 == 1) && (dig.r1 == 0))
		{
		tankturn_left(50,10,0);
		reflectance_digital(&dig);
		}
		else if ((dig.l3 == 1) && (dig.r3 == 1))
    	{
    		motor_forward(0,0);
    		reflectance_digital(&dig);
    	}

	}
}

void tankturn_right(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}
void tankturn_left(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(0);     // set RightMotor forward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}

#endif 

#if 0
//Assignment 1 week 4
void Go_Stop (void);
void Go_Stop2 (void);
struct sensors_ dig;

void zmain(void)
{

//struct sensors_ ref;


reflectance_start();
reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
//SW1_Read(); //button 


for(;;)
    {
        // read digital values that are based on threshold. 0 = white, 1 = black
        reflectance_digital(&dig); 
        //dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3
        vTaskDelay(0);
    if (SW1_Read()== 0)// button press
    {
        Go_Stop();
        IR_Start();
        IR_flush();
    	IR_wait();
		Go_Stop2();
}
    else 
        motor_forward(0,0);

    }





}
void Go_Stop2 (void)
{
	uint8_t i=0;
    uint8_t enable=0;
	//motor_start();
	//motor_forward(0,0);
	while(i<3)
	{
		//print_mqtt("Zumo006/debug", "Start");
        
        reflectance_digital(&dig);
		if (((dig.l3 == 1) && (dig.r3 == 1))&& enable==1)
        {
         i++;
            enable=0;
           
        }
		else if(!((dig.l3 == 1) && (dig.r3 == 1))&& enable ==0) 
		{	
        enable=1;
        }
        else
        motor_forward(75,1);
    }   
    motor_forward(0,0);
}

void Go_Stop (void)
{
   
	motor_start();
	motor_forward(0,0);
    
while (1)
{
    reflectance_digital(&dig);
while ((dig.l3 == 0) && (dig.r3 == 0))
   {
    //reflectance_digital(&dig);	
    motor_forward(100,0);
    reflectance_digital(&dig);
    }
if ((dig.l3 == 1) && (dig.r3 == 1))
    {
    motor_forward(0,0);
    reflectance_digital(&dig);
    break;
    }
    
}
}
#endif 
 

#if 1
    //Assigment 2 week 4
void Go_Stop (void);
struct sensors_ dig;
void Follow_Line_Stop(void);
void turn_right();
void turn_left();
void tankturn_right();
void tankturn_left();
uint8_t speed;
uint32_t delay;
uint8_t f_speed;
uint8_t b_speed;

void zmain(void)
{
reflectance_start();
reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000); // set center sensor threshold to 11000 and others to 9000
// void IR_wait(void); //wait for any IR 

for(;;)
    {
        // read digital values that are based on threshold. 0 = white, 1 = black
        reflectance_digital(&dig); 
        printf("DIG l3:%d. l2:%d. l1:%d. r1:%d. r2:%d. r3:%d.\n", dig.l3, dig.l2, dig.l1, dig.r1, dig.r2, dig.r3);         
        vTaskDelay(0);
    
    
    if (SW1_Read()== 0)// button press
    {
        Go_Stop();
        IR_Start(); // start IR receiving
        IR_flush(); // clear IR receive buffer
   		IR_wait();
        
        

        
        motor_forward(100,300);
   		Follow_Line_Stop(); //what if here just the  move forward

        turn_left();  

   		Follow_Line_Stop();

  		turn_right();

   		Follow_Line_Stop();

   		turn_right();

  		Follow_Line_Stop();

    }
    else
        motor_forward(0,0);

    }
}

void Go_Stop (void)
{
   
	motor_start();
	motor_forward(0,0);
    
while (1)
{
    reflectance_digital(&dig);
while ((dig.l3 == 0) && (dig.r3 == 0))
   {
    //reflectance_digital(&dig);	
    motor_forward(50,0);
    reflectance_digital(&dig);
    }
if ((dig.l3 == 1) && (dig.r3 == 1))
    {
    motor_forward(0,0);
    reflectance_digital(&dig);
    break;
    }
    
}
}

void Follow_Line_Stop(void)
{
    int done=0;
	while (done==0)
	{
        
		reflectance_digital(&dig);
		if ((dig.l1 == 1) && (dig.r1 == 1))
		{
			motor_forward(75,0);
			reflectance_digital(&dig);
        }   
		else if ((dig.l2 == 1) && (dig.r2 == 1))
    	{
    		motor_forward(0,0);
            done=1;     
            //break;
    	}
    
	}
}

void tankturn_right(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}
void tankturn_left(f_speed, b_speed, delay)
{
	MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(0);     // set RightMotor forward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}


void turn_left ()
{
	
	reflectance_digital(&dig);
	while (!((dig.l1 == 1 && dig.r1 == 1) && (dig.l2 == 0 && dig.r2 == 0)))
    {
        reflectance_digital(&dig);
        tankturn_left(25,25,1);
        reflectance_digital(&dig);
        vTaskDelay(200);
        //print_mqtt("Zumo006/debug","Tankturn left. l1: %d r1: %d. l3: %d, r3: %d", dig.l1, dig.r1, dig.l3, dig.r3);
    }
     
}
void turn_right()
{
	reflectance_digital(&dig);
	while (!((dig.l1 == 1 && dig.r1 == 1) && (dig.l2 == 0 && dig.r2 == 0)))
    {
        
        tankturn_right(25,25,1);
        reflectance_digital(&dig);
        reflectance_digital(&dig);
        vvTaskDelay(200);

    }
       
}



#endif 

#if 0

//ultrasonic sensor_mqtt assigment 2 week 5//
void random_reverse();
void tankturn_right();
void tankturn_left();
uint8_t speed;
uint32_t delay;
uint8_t f_speed;
uint8_t b_speed;
int motorVelocity = 60;
void beep_reverse();
int d = 0; // Print the detected distance (centimeters)
    
void zmain(void)
{
    int ctr = 0;

    printf("\nBoot\n");
    send_mqtt("Zumo006/debug", "Boot");
    
    
    Ultra_Start();              // Ultra Sonic Start function
   
    motor_start();              // enable motor controller
    motor_forward(0,0);     // moving forward
    
    vTaskDelay(500);


for(;;)
{
    
    while(1) {
        
        d = Ultra_GetDistance(); // Print the detected distance (centimeters)
    
        if(d <= 10) // if the distance is less than 10 cm
        
         {
            motor_forward(0,0);         // set speed to zero to stop motor
            vTaskDelay(500);
            reverse_randon_turn1();
            vTaskDelay(100);
            
          }
        else if (d <= 15)
        {
            motor_forward(0,0);         // set speed to zero to stop motor
            vTaskDelay(500);
            reverse_randon_turn2();
            vTaskDelay(100);
        }
        
        else // if the distance is moore than 10 cm
        
         {
            motor_forward(100,0);         // set speed to zero to stop motor
            vTaskDelay(0);
         }
    }
        
     vTaskDelay(10);
}
}
        
void tankturn_right(f_speed, b_speed, delay)
{
    MotorDirLeft_Write(0);      // set LeftMotor forward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);
}
void tankturn_left(f_speed, b_speed, delay)
{
    MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(0);     // set RightMotor forward mode
    PWM_WriteCompare1(f_speed); 
    PWM_WriteCompare2(b_speed); 
    vTaskDelay(delay);


void reverse_random_turn1()
{
    motor_backward(100,2000);
    tankturn_right(100,100,250);
    i=0;
    print_mqtt("Zumo006/Turn Right", n, ctr, SW1_Read());
    n = rand()%3;
    break;
}
    


void reverse_random_turn2()
{
    random_reverse();
    tankturn_left(100,100,250);
    i=0;
    print_mqtt("Zumo006/Turn Left", n, ctr, SW1_Read());
    n = rand()%3;
    break;

}

#endif

/* [] END OF FILE */
