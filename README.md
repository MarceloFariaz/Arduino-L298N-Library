# Arduino L298N Library
A simple library for use the driver motors L298n

## Installation

1. [Download](https://github.com/MarceloFariaz/Arduino-L298N-Library/archive/master.zip) the Latest release from GitHub.
2. Unzip and modify the Folder name to "L298N" (Remove the '-version')
3. Paste the modified folder on your Library folder (On your `Libraries` folder inside Sketchbooks or Arduino software).
4. Re-open Arduino Software

## Getting Started

```c++
#define ENA 6 //this pin must be connected to a PWM output
#define IN1 7
#define IN2 8
#define ENB 9 //this pin must be connected to a PWM output
#define IN3 10
#define IN4 11

L298N myMotors = L298N(ENA, IN1, IN2, ENB, IN3, IN4);
```

### TIPs and Warnings

(...)

## Library Reference

(...)

### You should know:
- `L298N L298N::setMaxSpeedA(int max_speed_a)` - Sets the maximum speed of Motor A (0 - 255);
- `L298N L298N::setMaxSpeedB(int max_speed_b)` - Sets the maximum speed of Motor B (0 - 255);
- `L298N L298N::setMaxSpeed(int max_speed_a, int max_speed_b)` - Sets the maximum speed of the two Motors (0 - 255);
- `L298N L298N::setMaxSpeed(int max_speed)` - Sets the same maximum speed of the two Motors (0 - 255);
- `L298N L298N::setMinSpeedA(int min_speed_a)` - Sets the minimum speed of Motor A (0 - 255);
- `L298N L298N::setMinSpeedB(int min_speed_b)` - Sets the minimum speed of Motor B (0 - 255);
- `L298N L298N::setMinSpeed(int min_speed_a, int min_speed_b)` - Sets the minimum speed of the two Motors (0 - 255);
- `L298N L298N::setMinSpeed(int min_speed)` - Sets the same minimum speed of the two Motors (0 - 255);
- `int L298N::speedA()` - Returns the current speed of Motor A (0 - 100);
- `int L298N::speedB()` - Returns the current speed of Motor B (0 - 100);
- `L298N L298N::setSpeedA(int speed_a)` - Sets the speed of Motor A (0 - 100);
- `L298N L298N::setSpeedB(int speed_b)` - Sets the speed of Motor B (0 - 100);
- `L298N L298N::setSpeed(int speed_a, int speed_b)` -  Sets the speed of the two Motors (0 - 100);
- `L298N L298N::setSpeed(int speed)` - Sets the same speed of the two Motors (0 - 100);
- `L298N L298N::fastBrakeA()` - brake Motor A, a "Fast brake";
- `L298N L298N::fastBrakeB()` - brake Motor B, a "Fast brake";
- `L298N L298N::fastBrake()` - brake Motors, a "Fast brake";
- `L298N L298N::freeBrakeA()` - brake Motor A, a "Free brake";
- `L298N L298N::freeBrakeB()` - brake Motor B, a "Free brake";
- `L298N L298N::freeBrake()` - brake Motors, a "Free brake";
- `L298N L298N::setBrakeA(int brake_a)` - Sets the standard brake of the Motor B (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298N L298N::setBrakeB(int brake_b)` - Sets the standard brake of the Motor A (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298N L298N::setBrake(int brake_a, int brake_b)` - Sets the standard brake of the two Motors (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298N L298N::setBrake(int brake)` - Sets the same standard brake of the two Motors (`FAST_BRAKE` or `FREE_BRAKE`);

### You don't need to know:

### Hardware Information
- The ENA and ENB pins must be connected to PWM outputs!
  More information: http://www.arduino.cc/en/Reference/analogWrite
