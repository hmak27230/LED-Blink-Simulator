#include "LED.h"

// Initialize the LEDs (configure the GPIO pins connected to the LEDs as outputs)
void LED_Init(void) {
    // Power up GPIO peripheral for LEDs
    LPC_SC->PCONP |= (1 << 15);  // Power up GPIO by setting bit 15 in the PCONP register

    // Configure LED pins (assumed to be on P2.0 to P2.7) as output
    LPC_GPIO2->FIODIR |= 0xFF;  // Set P2.0 to P2.7 as output (for 8 LEDs)
}

// Turn on a specific LED (assume LED number corresponds to bits in GPIO2)
void LED_On(uint32_t led) {
    LPC_GPIO2->FIOSET = (1 << led);  // Set the corresponding bit to turn on the LED
}

// Turn off a specific LED
void LED_Off(uint32_t led) {
    LPC_GPIO2->FIOCLR = (1 << led);  // Clear the corresponding bit to turn off the LED
}

// Turn off all LEDs (clear all bits controlling the LEDs)
void LED_OffAll(void) {
    LPC_GPIO2->FIOCLR = 0xFF;  // Clear bits 0-7 to turn off all LEDs
}
