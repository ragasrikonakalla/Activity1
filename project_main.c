#include <avr/io.h>
#include<util/delay.h>

#include "activity1.h" // B3, B2 input pins to high results B0 output pin to high
#include "activity2.h" // AC0 is used as input to vary temperature 
#include "activity3.h" // OC1A (B1) to output pwm signal
#include "activity4.h" // UART0 is used to actuate the amount of heat

int main(void)
{
    activity1_init();  // activity1
    initADC();         // activity2
    initUART(103);     // activity4
    uint16_t temp;     // activity3
    char temp1;
    while(1){
            if( !(SENSOR_ON)) {       // Switch1 ON
                if(!(HEATER_ON)) {    // Switch2 ON
                    LED_ON;         // LED ON
                    temp=ReadADC(0);
                    temp1=PWM(temp);
                    UARTwrite(temp1);

                 }
            }

            else {
            LED_OFF;
            OCR1A=0;
            }
      }

    return 0;
}

