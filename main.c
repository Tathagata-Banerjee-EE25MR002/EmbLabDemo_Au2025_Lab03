#include <stdint.h>
#include "tm4c123gh6pm.h"

// Define PortF data register
#define GPIO_PORTF_DATA_R   (*((volatile uint32_t *)0x400253FC))

// Define LED pin (Red LED = PF1)
#define RED_LED   (1U << 1)

int main(void) {
    // Normally, GPIO direction and digital enable setup code is needed here
    // (skipped for simplicity if already configured in Lab setup)

    while(1) {
        GPIO_PORTF_DATA_R ^= RED_LED;  // Toggle RED LED (R-M-W)
        
        for (volatile int i = 0; i < 1000000; i++); // Delay loop
    }
}

