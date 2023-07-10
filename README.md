# Line_follower_b-w_w-b
# README

This is a code snippet that involves controlling LEDs based on analog input from potentiometers. The code uses Arduino syntax and is intended to be run on an Arduino board.

## Hardware Setup

To use this code, you need the following components:

- An Arduino board
- Three potentiometers connected to analog input pins A2, A1, and A0
- Three LEDs connected to digital output pins 6, 7, and 8
- Two LEDs connected to analog output pins 9 and 10

Make sure to connect the components correctly according to the pin assignments mentioned in the code.

## Code Explanation

The code includes several functions and variables to control the behavior of the LEDs based on the potentiometer values.

- `small_right_down()`, `right_down()`, `small_left_down()`, `left_down()`, and `straight()` functions are responsible for setting the analog output values to control the LEDs.
- The `setup()` function is called once when the board is powered on or reset. It sets the specified pins as outputs.
- The `white_line()` function reads the potentiometer values and adjusts the LED outputs accordingly when there is a white line on a black background.
- The `black_line()` function reads the potentiometer values and adjusts the LED outputs accordingly when there is a black line on a white background.

### White Line on Black Background

The `white_line()` function performs the following steps:

1. Read the potentiometer values and store them in `sensorValue0`, `sensorValue1`, and `sensorValue2`.
2. Determine whether the potentiometer values indicate a white line or not based on a threshold (in this case, 600). If a potentiometer value is above the threshold, it is considered as a white line; otherwise, it is not.
3. Set the corresponding output values (`outputValue0`, `outputValue1`, `outputValue2`) to 1 if the potentiometer value indicates a white line, or set them to 0 if not.
4. Control the LEDs (`LEDPin0`, `LEDPin1`, `LEDPin2`) based on the output values. If the output value is 0, the LED is turned off; if the output value is 1, the LED is turned on.
5. Set the `RB0`, `RB1`, and `RB2` variables to the corresponding output values for later use.
6. Check the previous line tracking direction (`last_time`) and adjust the motor outputs accordingly based on the line tracking conditions.

### Black Line on White Background

The `black_line()` function performs similar steps to `white_line()`, but with different threshold values and line tracking conditions to handle a black line on a white background.

## Usage

1. Set up the hardware as described in the "Hardware Setup" section.
2. Connect your Arduino board to your computer.
3. Open the Arduino IDE or any other compatible IDE.
4. Create a new sketch and paste the provided code into the sketch.
5. Verify the code for any syntax errors.
6. Upload the code to your Arduino board.
7. Observe the behavior of the LEDs based on the potentiometer values and the line/background conditions.

Note: Make sure you have the necessary libraries installed to compile and run the code successfully.

Feel free to modify the code to suit your specific requirements and experiment with different LED control patterns based on the potentiometer values and line/background conditions.
