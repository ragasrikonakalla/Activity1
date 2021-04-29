#include <avr/io.h>
#include <activity1.h>
#include <activity2.h>
//pins used are: 
//B0 as output and initalized to 0
//B1 as Input and initialize it to high
//B2 as Input and initialize it to high
int main(void)
{
    activity1_init();
    initADC();
    uint16_t temp;
    while(1){
		if( !(PINB & (1<<PB1))) {
                if(!(PINB & (1<<PB2))) {
                    PORTB |= (1<<PB0);
                    temp=ReadADC(0);
                 }
        }
        else {
            PORTB &=~(1<<PB0);
        }
      }

    return 0;
}

