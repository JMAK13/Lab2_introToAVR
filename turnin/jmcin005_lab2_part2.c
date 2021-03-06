/*	Author: jmcin005
 *  Partner(s) Name: n/a
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 2
 *	Exercise Description: Port A's pins 3 to 0, each connect to a parking space sensor, 1 meaning a car is parked
                          in the space, of a four-space parking lot. Write a program that outputs in binary on
                          port C the number of available spaces (Hint: declare a variable "unsigned char
                          cntavail"; you can assign a number to a port as follows: 
PORTC = cntavail;).
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
    unsigned char remain;
    while(1) {
        tmpA3 = PINA & 0x08;     // Read input
        tmpA2 = PINA & 0x04;
        tmpA1 = PINA & 0x02;
        tmpA0 = PINA & 0x01;
        remain = 0x04;
        if(tmpA3 == 0x08) {
            remain = remain-0x01;
            tmpA3 = 0x00;
        }
        if(tmpA2 == 0x04) {
            remain = remain-0x01;
            tmpA2 = 0x00;
        }
        if(tmpA1 == 0x02) {
            remain = remain-0x01;
            tmpA1 = 0x00;
        }
        if(tmpA0 == 0x01) {
            remain = remain-0x01;
            tmpA0 = 0x00;
        }
        PORTC = remain;
    }    

    return 1;
}
