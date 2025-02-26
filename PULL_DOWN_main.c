#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>//header file which contain inbuild libraries
#define _XTAL_FREQ 6000000 //Oscilator frequency with 6MHz

//////////////this code is pull down circuit/////////////


void main(void) { //main block fo code
    TRISC = 0x0F; //set the port C RC0, RC1, RC2, RC3 ad Input by making it as HIGH(1)
    PORTC = 0X00; //set the initial value of PORTC as LOW(0)
    TRISD = 0x00; //set all the PORTD as output by making it as LOW(0)
    PORTD = 0x00; //set the initial value of PORTD as LOW(0)
    
    while(1){ //while loop wil execute untill the simulation stop
        unsigned int val = PORTC;//declare a varialbe to store the state of port C
        switch(val){//swich satament begining
            case 0x01: //if the state of PORTC is 8'b00000001 then PORT D is set to 8'b00100000
                PORTD = 0x20;//8'b00100000
                break;//break the sate else it will execute the next line
            case 0x02://if the state of PORTC is 8'b00000010 then PORT D is set to 8'b00001000
                PORTD = 0x08;//8'b00001000
                break;//break the sate else it will execute the next line
            case 0x04://if the state of PORTC is 8'b00000100 then PORT D is set to 8'b00101000
                PORTD = 0x28;//8'b00101000
                break;//break the sate else it will execute the next line
            case 0x08://if the state of PORTC is 8'b00001000 then PORT D is set to 8'b00000000
                PORTD = 0x00;//8'b00000000
                break;//break the sate else it will execute the next line
            default :
                PORTD = 0x00 ;//8'b00000000
                break;//break the sate else it will execute the next line
        }
    }
    return;
}
//clean and build the code to get the .hex file