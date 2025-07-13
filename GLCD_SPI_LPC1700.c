#include "GLCD_SPI_LPC1700.h"

// Function to send command to LCD (implementation may vary based on your specific LCD controller)
void GLCD_SendCommand(uint8_t cmd) {
    // Logic to send command to LCD (SPI, GPIO control)
    // Assuming the use of SPI to send the command
}

// Function to send data to LCD
void GLCD_SendData(uint8_t data) {
    // Logic to send data to LCD (SPI, GPIO control)
    // Assuming the use of SPI to send the data
}

// Initialize the LCD
void GLCD_Init(void) {
    // Initialize the SPI communication or GPIOs required for the LCD
    // Send initialization commands to the LCD
    GLCD_SendCommand(0x01);  // Example: Software reset command (depending on your LCD)
    // Further commands to initialize the LCD
    GLCD_Clear(White);       // Clear the screen with white color
}

// Clear the LCD screen with a specific color
void GLCD_Clear(uint16_t color) {
    // Logic to clear the screen by filling it with the specified color
    // Loop through each pixel on the display and set it to the specified color
    GLCD_SendCommand(0x2C);  // Memory write command (example)
    
    for (int i = 0; i < 320 * 240; i++) {  // Assuming a 320x240 resolution
        GLCD_SendData(color >> 8);         // Send high byte
        GLCD_SendData(color & 0xFF);       // Send low byte
    }
}

// Display a string at a specific position (line and position within the line)
void GLCD_DisplayString(uint32_t line, uint32_t pos, uint32_t font_size, const char *text) {
    // Logic to display text on the LCD at a specific line and position
    // Convert text to pixel data and send it to the LCD

    // Example: Write characters to the LCD (for simplicity, assuming 8-bit font)
    while (*text) {
        // Send character data to the LCD, assuming 8x8 pixel characters
        GLCD_SendCommand(0x2C);  // Memory write command
        // Convert the character to pixel data and write to the LCD
        // (This would depend on the font used and how characters are stored)
        text++;  // Move to the next character
    }
}

// Clear a specific line on the LCD (fill it with a blank color)
void GLCD_ClearLn(uint32_t line, uint32_t font_size) {
    // Logic to clear a specific line by filling it with the background color (White)
    // Calculate the pixel range for the line and clear it
    GLCD_DisplayString(line, 0, font_size, "                    "); // Fill line with blank spaces
}
