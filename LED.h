#ifndef LED_H
#define LED_H

#include <LPC17xx.H>  // LPC1768 definitions

// Function declarations for controlling the LEDs
void LED_Init(void);      // Initialize the LEDs
void LED_On(uint32_t led); // Turn on a specific LED
void LED_Off(uint32_t led); // Turn off a specific LED
void LED_OffAll(void);    // Turn off all LEDs

#endif // LED_H
