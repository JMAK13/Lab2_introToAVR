/*	Author: jmcin005
 *  Partner(s) Name: n/a
 *	Lab Section: 022
 *	Assignment: Lab 2  Exercise 1
 *	Exercise Description: Garage open at night-- A garage door sensor connects to PA0 (1 means door open),
                          and a light sensor connects to PA1 (1 means light is sensed). Write a program
                          that illuminates an LED connected to PB0 (1 means illuminate) if the garage door
                          is open at night.
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
    DDRB = 0xFF; PORTB = 0x00;	// Configure port B's 8 pins as outputs
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    while(1) {
        tmpA = PINA & 0x03;     // Read input
        if(tmpA == 0x01) {
            tmpB = (tmpB & 0xFE) | tmpA;
        } else {
            tmpB = (tmpB & 0x00);
        }
        PORTB = tmpB;
    }    

    return 1;
}
