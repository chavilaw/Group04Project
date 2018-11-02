#if 0
//ultrasonic sensor//


void zmain(void)
{
    Ultra_Start();              // Ultra Sonic Start function
    
    motor_start();              // enable motor controller
    motor_forward(100,2000);     // moving forward
    
    vTaskDelay(3000);
    
}

for(;;)
{
    
    while(1) {
        int d = Ultra_GetDistance(); // Print the detected distance (centimeters)
        
        
        if(d = > 10) // if the distance is less than 10 cm
        
         {
            motor_forward(0,0);         // set speed to zero to stop motor
            vTaskDelay(500);
            command_2();
            vTaskDelay(100);
            --d;
         }
    }
        
     vTaskDelay(10);
}
        

void command_2();
{
   Beep(1000, 150);
   motor_backward(100,2000);    // moving backward
            
   motor_turn(200,50,2000)
        while motor_backward(100,2000);     // turn
                
   motor_turn(50,200,2000)
        while motor_backward(100,2000);     // turn


}
    
    
    
 

#endif
