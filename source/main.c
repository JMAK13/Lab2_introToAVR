/*	Author: jmcin005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0x00;  // Configure port A, B, and C's 8 pins as inputs
    DDRB = 0x00; PORTB = 0x00;
    DDRC = 0x00; PORTC = 0x00;
    DDRD = 0xFF; PORTD = 0x00;	// Configure port D's 8 pins as outputs
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    unsigned char sum = 0x00;
    while(1) {
        tmpA = PINA;     // Read inputs
        tmpB = PINB;
        tmpC = PINC;
        tmpD = 0;
        sum = 0;
        if(tmpA - tmpC > 80 || tmpC - tmpA > 80) tmpD = 0x02;
        sum = tmpA + tmpB + tmpC;
        if(sum > 140) tmpD++;
        PORTD = tmpD;
    }    

    return 1;
}
