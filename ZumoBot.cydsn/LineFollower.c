#if 1
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