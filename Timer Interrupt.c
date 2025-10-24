/*
 * File:   Timer Interrupt.c
 * Author: asath
 *
 * Created on 24 October, 2025, 6:18 PM
 */


#include <xc.h>
#define _XTAL_FREQ 20000000

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

unsigned char timer_count = 0;
    
    void interrupt timer_0()
    {
        if(INTCONbits.TMR0IF ==1)
        {
            timer_count++;
            INTCONbits.TMR0IF = 0;
        }
    }

void main(void) 
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    
    OPTION_REG = 0x07;
    TMR0 = 59; // 10 micro seconds
    
    TRISB0 = 0;
    while(1)
    {
        if(timer_count == 0)
        {
            PORTBbits.RB0 = 1;
        }
        if(timer_count == 100)
        {
            PORTBbits.RB0 = 0;
        }
        if(timer_count == 200)
        {
            timer_count = 0;
        }
    }
    return;
}
