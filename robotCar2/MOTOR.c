#include "MOTOR.h"
#include "PINS.c"
// one pair is controlled by in1, and 2 and the other pair is controlled by IN3, and 4
void motorSetup()
{
    pwmSetup();

    DDRB |= (1<<IN2) | (1<<IN3) | (1<<IN4);
	DDRD |= (1<<IN1);
    PORTB &= ~((1<<IN2) | (1<<IN3) | (1<<IN4));
	PORTD &= ~(1<<IN1);
}

void forward()
{
    PORTD |= (1<<IN1);   // IN1 = HIGH
    PORTB &= ~(1<<IN2);  // IN2 = LOW
    PORTB &= ~(1<<IN3);   // IN3 = HIGH
    PORTB |= (1<<IN4);  // IN4 = LOW

    PORTC &= (~(1<<LED_left)) & (~(1<<LED_right));

    OCR0B = MAXSPEED / 4;
    OCR0A = MAXSPEED / 4;
    dir = FWD;
}

void backward()
{
    PORTD &= ~(1<<IN1);  // IN1 = LOW
    PORTB |= (1<<IN2);   // IN2 = HIGH
    PORTB &= ~(1<<IN3);  // IN3 = LOW
    PORTB |= (1<<IN4);   // IN4 = HIGH

    PORTC |= (1<<LED_left) | (1<<LED_right);

    OCR0B = MAXSPEED;
    OCR0A = MAXSPEED;
    dir = BWD;
}

void left()
{
    PORTD &= ~(1<<IN1);  // IN1 = LOW
    PORTB |= (1<<IN2);   // IN2 = HIGH
    PORTB |= (1<<IN3);   // IN3 = HIGH
    PORTB &= ~(1<<IN4);  // IN4 = LOW

    PORTC |= (1<<LED_left);
	PORTC &= (~(1<<LED_right));

    OCR0B = MAXSPEED;
    OCR0A = MAXSPEED;
    dir = LT;
}

void right()
{
    PORTD |= (1<<IN1);   // IN1 = HIGH
    PORTB &= ~(1<<IN2);  // IN2 = LOW
    PORTB &= ~(1<<IN3);  // IN3 = LOW
    PORTB |= (1<<IN4);   // IN4 = HIGH

    PORTC &= (~(1<<LED_left));
	PORTC |= (1<<LED_right);

    OCR0B = MAXSPEED;
    OCR0A = MAXSPEED;
    dir = RT;
}

void softLeft()
{
    PORTD &= ~(1<<IN1);  // IN1 = LOW
    PORTB |= (1<<IN2);   // IN2 = HIGH
    PORTB |= (1<<IN3);   // IN3 = HIGH
    PORTB &= ~(1<<IN4);  // IN4 = LOW

    PORTC |= (1<<LED_left);
	PORTC &= (~(1<<LED_right));

    OCR0B = MINSPEED;
    OCR0A = MAXSPEED;
    dir = SLT;
}

void softRight()
{
    // Assuming logic for soft right turn
    PORTD |= (1<<IN1);   // IN1 = HIGH
    PORTB &= ~(1<<IN2);  // IN2 = LOW
    PORTB &= ~(1<<IN3);  // IN3 = LOW
    PORTB |= (1<<IN4);   // IN4 = HIGH

    PORTC &= (~(1<<LED_left));
	PORTC |= (1<<LED_right);

    OCR0B = MAXSPEED;
    OCR0A = MINSPEED;
    dir = SRT;
}


void stop()
{
    PORTB &= ~((1<<IN2) | (1<<IN3) | (1<<IN4));
	PORTD &= ~(1<<IN1);
    OCR0B = 0;
    OCR0A = 0;
    dir = STOP; 
    PORTC &= (~(1<<LED_left)) & (~(1<<LED_right));
}

//D5 and D6 for timer0 
void pwmSetup()
{
    DDRD |= (1<<DDD5) | (1<<DDD6);
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    TCCR0B |= (1 << CS01) | (1 << CS00);
}