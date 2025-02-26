#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
//configuration bit generated code
#define _XTAL_FREQ 6000000 //Oscilator frequnecy 6MHz
//main code block
void main(void) { //main code
    TRISB = 0XF0; //set the RB7, RB6, RB5, RB4 as ouput by making it as 1
    TRISC = 0X00; //set all the C port as output
    PORTC = 0X00; //set the initial value of port C as LOW(0)
    PORTB = 0X00; //set the initial value of PORT B as LOW(0)
    while(1){ //while loop which is going to repeat again and again untill the simulation stops
        unsigned int val = PORTB; //declare a variable to store the value of PORTB
        switch(val){ //Switch case to check the state of the switch
            //if the bit match with 11100000 then PORTC is assigned to 0X02
            case 0xE0: //8'b11100000
                PORTC = 0X02; //port C is assigned to 0x02 ==> 8'b00000010
                break; //break the loop, if not break the loop it will go to the next line
            //if the bit match with 11010000 then PORTC is assigned to 0X42
            case 0xD0: //8'b11010000
                PORTC = 0X42; //port C is assigned to 0x42 ==> 8'b01000010
                break;//break the loop, if not break the loop it will go to the next line
            //if the bit match with 10110000 then PORTC is assigned to 0X40
            case 0xB0: //8'b10110000
                PORTC = 0X40; //8'b01000000
                break;//break the loop, if not break the loop it will go to the next line
            //if the bit match with 01110000 then PORTC is assigned to 0X00
            case 0x70: //8'b01110000
                PORTC = 0X00; //8'b00000000
                break;//break the loop, if not break the loop it will go to the next line
            default: //default condition which will execute when none of the condition was matched
                PORTC = 0X00; //8'b00000000
                break;//break the loop, if not break the loop it will go to the next line
        }
    }
    return;
}
//then build the program and get the .hex file