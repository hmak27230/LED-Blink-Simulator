#include <LPC17xx.H>   // LPC1768 definitions
#include "Blinky.h"    // Blinky header
#include "KBD.h"       // Joystick header
#include "LED.h"       // LED header
#include "GLCD_SPI_LPC1700.h" // LCD header

#ifdef _USE_LCD
    #define LCD_ENABLED 1
#else
    #define LCD_ENABLED 0
#endif

// Function to initialize all peripherals
void init_peripherals(void) {
    // Initialize LEDs
    LED_Init();

    // Initialize Joystick
    KBD_Init();

    // Initialize LCD if it's enabled
    if (LCD_ENABLED) {
        GLCD_Init();
        GLCD_Clear(White);
        GLCD_DisplayString(0, 0, 1, "Joystick Direction");
    }
}

// Function to update LEDs and LCD based on joystick input
void updateDisplay(uint32_t joystick_val) {
    // Clear all LEDs
    LED_OffAll();

    // Clear previous LCD line (if LCD is enabled)
    if (LCD_ENABLED) {
        GLCD_ClearLn(1, 1);
    }

    // Determine which direction the joystick is pressed and update LEDs and LCD
    if (joystick_val & KBD_UP) {
        LED_On(0);  // Turn on LED for 'UP' direction
        if (LCD_ENABLED) GLCD_DisplayString(1, 0, 1, "UP");
    } else if (joystick_val & KBD_DOWN) {
        LED_On(1);  // Turn on LED for 'DOWN' direction
        if (LCD_ENABLED) GLCD_DisplayString(1, 0, 1, "DOWN");
    } else if (joystick_val & KBD_LEFT) {
        LED_On(2);  // Turn on LED for 'LEFT' direction
        if (LCD_ENABLED) GLCD_DisplayString(1, 0, 1, "LEFT");
    } else if (joystick_val & KBD_RIGHT) {
        LED_On(3);  // Turn on LED for 'RIGHT' direction
        if (LCD_ENABLED) GLCD_DisplayString(1, 0, 1, "RIGHT");
    } else if (joystick_val & KBD_SELECT) {
        LED_On(4);  // Turn on LED for 'SELECT' direction
        if (LCD_ENABLED) GLCD_DisplayString(1, 0, 1, "SELECT");
    }
}

int main(void) {
    // Initialize peripherals (LEDs, Joystick, LCD)
    init_peripherals();

    while (1) {
        // Get the current joystick input
        uint32_t joystick_val = get_button();

        // Update display and LEDs based on joystick direction
        updateDisplay(joystick_val);
    }
}
