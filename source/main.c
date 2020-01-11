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
    DDRA = 0x00; PORTA = 0xFF;  // Configure port A's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00;	// Configure port C's 8 pins as outputs
    unsigned char tmpA3 = 0x00;
    unsigned char tmpA2 = 0x00;
    unsigned char tmpA1 = 0x00;
    unsigned char tmpA0 = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char remain = 0x04;
    while(1) {
        tmpA3 = PINA & 0x08;     // Read input
        tmpA2 = PINA & 0x04;
        tmpA1 = PINA & 0x02;
        tmpA0 = PINA & 0x01;
        remain = 0x04;
        if(tmpA3 == 0x08) {
            remain--;
            tmpA3 = 0x00;
        }
        if(tmpA2 == 0x04) {
            remain--;
            tmpA2 = 0x00;
        }
        if(tmpA1 == 0x02) {
            remain--;
            tmpA1 = 0x00;
        }
        if(tmpA0 == 0x01) {
            remain--;
            tmpA0 = 0x00;
        }

        tmpC = (tmpC & 0x00) | remain;
        if(remain == 0x00) (tmpC & 0x0F) | 0x80;
        PORTC = tmpC;
    }    

    return 1;
}
