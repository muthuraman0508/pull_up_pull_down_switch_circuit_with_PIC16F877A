#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h> //header file which contain necessary library
#define _XTAL_FREQ 6000000 //oscilator frequency with 6MHz


////THIS CODE IS FOR PULL UP CIRCUIT////
void main(void) { //main block 
    TRISC = 0x0F; //set the RC0, RC1, RC2, RC3 as input pin by making at as HIGH(1)
    PORTC = 0x00; //set the intial value of PORTC as low(0)
    TRISD = 0x00; //Set the PORT D as output pin
    PORTD = 0x00; //set the inital value as LOW(0)
    while(1) { //while loop will execute untill the execution stop
        unsigned int val = PORTC;//declare a variable val to store the value of PORTC state
        switch(val){ //swich which is going to check the state of the switch
            case 0x0E: //if the PORT D value is 8'b00001110 then the PORT D will set as 0x02
                PORTD = 0x20; //8'b00100000
                break; //break the case else it will execute the next line
            case 0x0D://if the PORT D value is 8'b00001101 then the PORT D will set as 0x08
                PORTD = 0x08; //8'b00001000
                break;//break the case else it will execute the next line
            case 0x0B://if the PORT D value is 8'b00001011 then the PORT D will set as 0x28
                PORTD = 0x28; //8'b00101000
                break;//break the case else it will execute the next line
            case 0x07://if the PORT D value is 8'b00000111 then the PORT D will set as 0x00
                PORTD = 0x00;//8'b00000000
                break;//break the case else it will execute the next line
            default://default case when non of the case was matched
                PORTD = 0x00;//8'b00000000
                break;//break the case else it will execute the next line
        }
    }
    return;
}
//clean and build to get the .hex file