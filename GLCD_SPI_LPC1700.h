#ifndef GLCD_SPI_LPC1700_H
#define GLCD_SPI_LPC1700_H

#include <LPC17xx.H>  // LPC1768 definitions

// LCD color definitions
#define White       0xFFFF
#define Black       0x0000
#define Blue        0x001F
#define Red         0xF800
#define Green       0x07E0
#define Yellow      0xFFE0

// Function declarations
void GLCD_Init(void);                                 // Initialize the LCD
void GLCD_Clear(uint16_t color);                      // Clear the screen with the specified color
void GLCD_DisplayString(uint32_t line, uint32_t pos, uint32_t font_size, const char *text); // Display a string at the specified location
void GLCD_ClearLn(uint32_t line, uint32_t font_size); // Clear a specific line

#endif // GLCD_SPI_LPC1700_H
