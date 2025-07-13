#ifndef KBD_H
#define KBD_H

#include <LPC17xx.H>  // LPC1768 definitions

// Joystick Direction Masks (bitmask values for each joystick direction)
#define KBD_SELECT    0x01  // Joystick pressed
#define KBD_UP        0x08  // Joystick moved up
#define KBD_RIGHT     0x10  // Joystick moved right
#define KBD_DOWN      0x20  // Joystick moved down
#define KBD_LEFT      0x40  // Joystick moved left
#define KBD_MASK      0x79  // Mask to filter out valid joystick directions

// External function declarations for joystick initialization and reading
void KBD_Init(void);       // Initialize the joystick
uint32_t KBD_get(void);    // Get joystick raw value
uint32_t get_button(void); // Get active joystick button pressed

#endif // KBD_H
