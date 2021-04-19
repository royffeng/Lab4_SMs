/*	Author: rfeng016
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

enum SM1_STATES { SM1_Start, B0Lit, B0Wait, B1Lit, B1Wait } state;

void Tick() {
    unsigned char A0 = PINA & 0x01;
    switch (state) {
        case SM1_Start:
            state = B0Lit;
            break;
        case B0Lit:
            state = A0 ? B0Lit : B0Wait;
            break;
        case B0Wait:
            state = A0 ? B1Lit : B0Wait;
            break;
        case B1Lit:
            state = A0 ? B1Lit : B1Wait;
            break;
        case B1Wait:
            state = A0 ? B0Lit : B1Wait;
            break;
        default:
            state = B0Lit;
            break;
    }
    switch (state) {
        case SM1_Start:
            PORTB = 0x01;
            break;
        case B0Lit:
            PORTB = 0x01;
            break;
        case B0Wait:
            PORTB = 0x01;
            break;
        case B1Lit:
            PORTB = 0x02;
            break;
        case B1Wait:
            PORTB = 0x02;
            break;
        default:
            PORTB = 0x00;
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
