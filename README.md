# LPC1768 LED Blinky Simulator

This project transforms a traditional embedded systems school project – controlling LEDs on an LPC1768 microcontroller – into an interactive web-based simulator. It allows users to visualize LED blinking patterns and joystick input, demonstrating different LED control methods (Masking, Function, Bit-banding) in a user-friendly digital environment.

## 🚀 Live Demo

Experience the simulator live on GitHub Pages: [https://hmak27230.github.io/LED-Blink-Simulator/]

## ✨ Features

*   **Interactive LED Array:** Visualize the state of 8 LEDs (LED0-LED7).
*   **Multiple Control Modes:**
    *   **Masking Mode:** Demonstrates controlling LEDs using bitwise masking operations.
    *   **Function Mode:** Simulates LED control through dedicated functions.
    *   **Bit-banding Mode:** Illustrates the concept of bit-banding for individual bit manipulation.
*   **Auto Cycle:** Automatically cycles through the different LED control demonstration modes.
*   **Joystick Controller:**
    *   Interactive joystick buttons (Up, Down, Left, Right, Center/Select).
    *   Real-time display of joystick direction on a simulated LCD screen.
    *   LEDs respond to joystick input, mimicking a physical setup.
*   **Status Panel:** Displays current mode, active LEDs, and cycle count.
*   **Responsive Design:** Optimized for various screen sizes.

## 💡 Project Motivation

This project originated from a physical embedded systems assignment involving the LPC1768 microcontroller and external LEDs. The goal was to:

*   **Digitalize a Physical Project:** Make the demonstration accessible without physical hardware.
*   **Enhance Understanding:** Provide a clear visual representation of how different programming techniques (masking, functions, bit-banding) affect hardware (LEDs).
*   **Create an Interactive Learning Tool:** Allow users to experiment with controls and observe immediate feedback.
*   **Showcase Web Development Skills:** Apply HTML, CSS, and JavaScript to build a functional and engaging web application.

## 🛠️ Technologies Used

*   **HTML5:** For structuring the web application.
*   **CSS3:** For styling and creating the visual components (LEDs, joystick, buttons).
*   **JavaScript (ES6+):** For implementing the simulation logic, interactivity, and dynamic updates.

## 💻 How to Run Locally

To set up and run this project on your local machine:

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/[your-github-username]/LPC1768-LED-Blinky-Simulator.git
    ```
2.  **Navigate to the project directory:**
    ```bash
    cd LPC1768-LED-Blinky-Simulator
    ```
3.  **Open `index.html`:**
    Simply open the `index.html` file in your preferred web browser. No server-side setup is required.

## 📄 Code Structure

The project consists of a single `index.html` file which includes the HTML structure, CSS styling, and JavaScript logic.

*   **`index.html`**: Contains the entire application.
    *   `<style>` tag: Defines all the CSS rules for the layout and appearance.
    *   `<script>` tag: Contains the `LPC1768Simulator` JavaScript class and its initialization.

### Key JavaScript Class: `LPC1768Simulator`

The core logic resides within the `LPC1768Simulator` class:

*   **`constructor()`**: Initializes LED states, modes, and sets up event listeners.
*   **`initializeLEDs()`**: Populates the `this.leds` array with references to LED DOM elements.
*   **`initializeControls()`**: Attaches event listeners to mode selection buttons (Masking, Function, Bit-banding, Auto Cycle).
*   **`initializeJoystick()`**: Sets up event listeners for joystick buttons (mousedown, mouseup, mouseleave).
*   **`handleJoystick(direction, pressed)`**: Manages joystick button states, updates the LCD display, and controls LEDs based on joystick input.
*   **`updateJoystickDisplay(direction)`**: Updates the text content of the simulated LCD screen.
*   **`updateJoystickLEDs(direction)`**: Turns on specific LEDs based on the active joystick direction.
*   **`setMode(mode)`**: Sets the current simulation mode and updates UI.
*   **`updateModeButtons()`**: Highlights the currently active mode button.
*   **`demonstrateMasking()`**: Simulates LED blinking using a masking pattern.
*   **`demonstrateFunction()`**: Simulates LED blinking using a function-like pattern.
*   **`demonstrateBitbanding()`**: Simulates LED blinking using an alternating bit-banding pattern.
*   **`toggleAutoMode()`**: Toggles the automatic cycling of demonstration modes.
*   **`startAutoMode()`**: Initiates the `setInterval` for auto-cycling through modes.
*   **`stopAutoMode()`**: Clears the auto-cycle interval.
*   **`turnOnLED(index)`**: Changes the visual state of a specific LED to 'on'.
*   **`turnOffLED(index)`**: Changes the visual state of a specific LED to 'off'.
*   **`turnOffAllLEDs()`**: Resets all LEDs to the 'off' state.
*   **`updateStatus()`**: Updates the status panel with current mode, active LED count, and cycle count.

## 🤝 Contributing

Feel free to fork this repository, open issues, or submit pull requests. Any contributions to improve the simulator or add new features are welcome!

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).
