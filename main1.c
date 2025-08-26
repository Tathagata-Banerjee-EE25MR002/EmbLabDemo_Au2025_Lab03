#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

int main(void)
{
    SYSCTL_RCGC2_R = 0x20;          // Enable clock for Port F
    GPIO_PORTF_LOCK_R = 0x4C4F434B;  // Unlock PF0
    GPIO_PORTF_CR_R   = 0x1F;        // Allow changes to PF0–PF4
    GPIO_PORTF_DIR_R  = 0x0E;        // PF1, PF2, PF3 = output; PF0, PF4 = input
    GPIO_PORTF_DEN_R  = 0x1F;        // Digital enable PF0–PF4
    GPIO_PORTF_PUR_R  = 0x11;        // Pull-up resistors for PF0 and PF4
    GPIO_PORTF_DATA_R = 0x0;             // LED OFF

    while(1){
        uint8_t sw1 = GPIO_PORTF_DATA_R & 0x10;  // Read PF4
        if (sw1 ==0){
            GPIO_PORTF_DATA_R = 0x02;
        }
        
        else if (sw2 ==0){
            GPIO_PORTF_DATA_R = 0x04;
        }
        
        else if (sw1==0 && sw2 ==0){
            GPIO_PORTF_DATA_R = 0x06;
        }
        
        else
            GPIO_PORTF_DATA_R = 0x0;
    }
}
