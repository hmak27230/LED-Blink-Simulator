#include <LPC17xx.H>
#include "KBD.h"

// Initialize Joystick (configure GPIO pins connected to the joystick)
void KBD_Init(void) {
    // Power up GPIO peripheral for the joystick
    LPC_SC->PCONP |= (1 << 15);  // Power up GPIO by setting bit 15 in the PCONP register

    // Configure joystick pins (P1.20, P1.23..P1.26) as GPIO input
    LPC_PINCON->PINSEL3 &= ~((3 << 8) | (3 << 14) | (3 << 16) | (3 << 18) | (3 << 20));  // Set P1.20, P1.23, P1.24, P1.25, P1.26 as GPIO

    // Set joystick pins as input (default state of FIODIR is input, but ensuring here)
    LPC_GPIO1->FIODIR &= ~((1 << 20) | (1 << 23) | (1 << 24) | (1 << 25) | (1 << 26));  // Set pins as input
}

// Get raw joystick value (returns the value of the joystick input pins)
uint32_t KBD_get(void) {
    uint32_t kbd_val;
    kbd_val = (LPC_GPIO1->FIOPIN >> 20) & KBD_MASK;  // Read joystick state from P1.20, P1.23..P1.26
    return kbd_val;
}

// Get the button pressed on the joystick (returns active direction)
uint32_t get_button(void) {
    uint32_t val = 0;
    val = KBD_get();            // Read raw joystick input
    val = (~val & KBD_MASK);    // Process it to get non-zero for the active button
    return val;
}
