#include "LPC17xx.h"
#include <stdio.h>

#define LED1_PIN (1 << 28) // P1.28 for LED1
#define LED2_PIN (1 << 2)  // P2.2 for LED2

// Bit-banding addresses for P1.28 and P2.2
#define BITBAND_BASE 0x22000000
#define PERIPHERAL_BASE 0x40000000

// Macros for bit-banding LED1 and LED2 (calculate bit-band address)
#define GPIO1_LED31 (*((volatile unsigned long *)0x233806F4)) // P1.31
#define GPIO1_LED29 (*((volatile unsigned long *)0x233806FC)) // P1.29
#define GPIO2_LED2  (*((volatile unsigned long *)0x23380A88)) // P2.2

// Delay function for visible LED toggling
void delay_ms(int ms) {
    for (int i = 0; i < ms; i++)
        for (int j = 0; j < 20000; j++);
}

// Initialization of GPIO ports for LEDs
void init_leds(void) {
    LPC_GPIO1->FIODIR |= LED1_PIN;  // Set P1.28 as output
    LPC_GPIO2->FIODIR |= LED2_PIN;  // Set P2.2 as output
}

// Masking method for LED control
void led_masking_on(void) {
    LPC_GPIO1->FIOSET = LED1_PIN;  // Turn on LED1 using masking
    LPC_GPIO2->FIOSET = LED2_PIN;  // Turn on LED2 using masking
}

void led_masking_off(void) {
    LPC_GPIO1->FIOCLR = LED1_PIN;  // Turn off LED1 using masking
    LPC_GPIO2->FIOCLR = LED2_PIN;  // Turn off LED2 using masking
}

// Function method for LED control
void led_function_on(void) {
    LPC_GPIO1->FIOSET = (1 << 29);  // Turn on LED1 using function
    LPC_GPIO2->FIOSET = (1 << 3);   // Turn on LED2 using function
}

void led_function_off(void) {
    LPC_GPIO1->FIOCLR = (1 << 29);  // Turn off LED1 using function
    LPC_GPIO2->FIOCLR = (1 << 3);   // Turn off LED2 using function
}

// Bit-banding method for LED control
void led_bitbanding_on(void) {
    GPIO1_LED31 = 1;  // Turn on LED1 using bit-banding
    GPIO2_LED2 = 1;   // Turn on LED2 using bit-banding
}

void led_bitbanding_off(void) {
    GPIO1_LED31 = 0;  // Turn off LED1 using bit-banding
    GPIO2_LED2 = 0;   // Turn off LED2 using bit-banding
}

// Barrel shifting method to calculate a value
void barrel_shifting_example(void) {
    int value = 5;
    int result = value << 2;  // Multiply by 4 using barrel shifter
    printf("Barrel shift result: %d\n", result);  // Display result
}

// Conditional execution to toggle LEDs (using 's' suffix and IT block)
void toggle_leds_conditional(void) {
    int r1 = 1, r2 = 1, r3 = 2;
    while (1) {
        __asm volatile (
            "SUBS %[res], %[val1], %[val2]\n"  // Subtract r1 from r2, update flags
            "ITE LT\n"                         // If-Then block, condition: Less Than
            "BLT bit_banding_mode\n"           // Branch to bit_banding_mode if less
            "BGT function_mode\n"              // Branch to function_mode if greater
            "B mask_mode\n"                    // Else branch to mask_mode
            :
            : [res] "r" (r1), [val1] "r" (r1), [val2] "r" (r2)
        );

        // Delay to make LED behavior visible
        delay_ms(1000);

        // Turn off all LEDs
        led_masking_off();
        led_function_off();
        led_bitbanding_off();

        // Delay between modes
        delay_ms(1000);
    }
bit_banding_mode:
    // Bit banding mode
    printf("bit banding mode\n");
    led_bitbanding_on();
    r1++;

    function_mode:
    // Function mode
    printf("function mode\n");
    led_function_on();
    r1 = 2;

    mask_mode:
    // Mask mode
    printf("mask mode\n");
    led_masking_on();
    r1 += 3;
}

// Main function to run the application
int main(void) {
    init_leds();  // Initialize GPIO pins for LEDs

    while (1) {
        // Toggle LEDs using masking
        printf("Masking mode\n");
        led_masking_on();
        delay_ms(1000);
        led_masking_off();
        delay_ms(1000);

        // Toggle LEDs using function method
        printf("Function mode\n");
        led_function_on();
        delay_ms(1000);
        led_function_off();
        delay_ms(1000);

        // Toggle LEDs using bit-banding
        printf("Bit-banding mode\n");
        led_bitbanding_on();
        delay_ms(1000);
        led_bitbanding_off();
        delay_ms(1000);

        // Perform barrel shifting example
        barrel_shifting_example();

        // Conditional execution example
        toggle_leds_conditional();
    }
}
