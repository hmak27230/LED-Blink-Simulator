#ifndef BLINKY_H
#define BLINKY_H

#include <LPC17xx.H>   // LPC1768 definitions

// Function to initialize peripherals used in the project
void init_peripherals(void);

// Function to update the display based on joystick input
void updateDisplay(uint32_t joystick_val);

// Function to enable or disable the LCD (if required)
void toggleLCD(void);

#endif // BLINKY_H
