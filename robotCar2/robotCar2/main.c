/*
 * main.c
 *
 * Created: 21-9-2021 20:06:52
 * Author : Hugo Arends
 */ 

#define F_CPU (16000000UL)
#include <avr/io.h>
#include "MOTOR.h"
#include <util/delay.h>

//int main(void)
//{
    //DDRB = (1<<DDB5);
//
    //sei();
	//SoftSerialInit();
	//motorSetup();
//
    //while (1) 
    //{
        //if(SoftSerialUnread() > 0)
        //{
            //char data = SoftSerialReceiveByte();
//
            //switch( data )
            //{
//
                //case 'F':
				//forward();
				//break;
				//
				//case 'S':
				//stop();
				//break;
            //}
//
        //}
    //}
//}

int main()
{
	//pinsSetup();
	//sei();
	SoftSerialInit();
	motor_init();
	
	while (1)
	{
		//if (SoftSerialUnread() > 0)
		//{
		//	char data = SoftSerialReceiveByte();
		//	switch(data)
		//	{
		//		case 'L':
		//		left();
		//		break;
		//	
		//		case 'R':
		//		right();
		//		break;
		//	
		//		case 'S':
		//		stop();
		//		break;
		//	}
		//}
		softLeft();
	}
}

