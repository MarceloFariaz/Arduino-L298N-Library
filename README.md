# Arduino L298x Library
A simple library for use the driver motors L298x

## Installation

1. [Download](https://github.com/MarceloFariaz/Arduino-L298x-Library/archive/master.zip) the Latest release from GitHub;
2. In Arduino IDE, go to Menu `Sketch->Include Library->Add .ZIP Library`;
3. Select the file downloaded and click on Open.

## Getting Started

```c++
#define ENA 6 //this pin must be connected to a PWM output
#define IN1 7
#define IN2 8
#define ENB 9 //this pin must be connected to a PWM output
#define IN3 10
#define IN4 11

L298x myMotors = L298x(ENA, IN1, IN2, ENB, IN3, IN4);
```

To set the `maximum PWM value` for the motors:

```c++
myMotors.setMaxSpeedA(200).setMaxSpeedB(200);
```

To set the `minimum PWM value` for the motors:

```c++
myMotors.setMinSpeedB(50).setMinSpeedB(50);
```

To set the `standard brake` for the motor A to `FASTBRAKE` and for motor B `FREEBRAKE`:

```c++
myMotors.setBrakeA(FASTBRAKE).setBrakeB(FREEBRAKE);
```

To set the `speed value` for the motors to `100% FORWARD`:

```c++
myMotors.setSpeedA(100).setSpeedB(100);
```

To set the `speed value` for the motors to `100% BACKWARD`:

```c++
myMotors.setSpeedA(-100).setSpeedB(-100);
```

To `brake the motors`:

```c++
myMotors.setSpeedA(0).setSpeedB(0);
//or
myMotors.brake();
//or
myMotors.fastBrake();
//or
myMotors.freeBrake();
```

### TIPs and Warnings

```c++
myMotors.setSpeedA(100).setSpeedB(100);
```

It's the same as:

```c++
myMotors.setSpeedA(100);
myMotors.setSpeedB(100);
```

And as:

```c++
myMotors.setSpeed(100, 100);
```

And as:

```c++
myMotors.setSpeed(100);
```

The same goes for the instructions:

```c++
setMaxSpeedA(int max_speed);
setMinSpeed(int min_speed);
setBrake(int brake);
```

`Braking the motors`
(...)

## Library Reference

### You should know:
- `L298x::setMaxSpeedA(int max_speed_a)` - Sets the maximum speed of Motor A (0 - 255);
- `L298x L298x::setMaxSpeedB(int max_speed_b)` - Sets the maximum speed of Motor B (0 - 255);
- `L298x L298x::setMaxSpeed(int max_speed_a, int max_speed_b)` - Sets the maximum speed of the two Motors (0 - 255);
- `L298x L298x::setMaxSpeed(int max_speed)` - Sets the same maximum speed of the two Motors (0 - 255);
- `L298x L298x::setMinSpeedA(int min_speed_a)` - Sets the minimum speed of Motor A (0 - 255);
- `L298x L298x::setMinSpeedB(int min_speed_b)` - Sets the minimum speed of Motor B (0 - 255);
- `L298x L298x::setMinSpeed(int min_speed_a, int min_speed_b)` - Sets the minimum speed of the two Motors (0 - 255);
- `L298x L298x::setMinSpeed(int min_speed)` - Sets the same minimum speed of the two Motors (0 - 255);
- `int L298x::speedA()` - Returns the current speed of Motor A (0 - 100);
- `int L298x::speedB()` - Returns the current speed of Motor B (0 - 100);
- `L298x L298x::setSpeedA(int speed_a)` - Sets the speed of Motor A (0 - 100);
- `L298x L298x::setSpeedB(int speed_b)` - Sets the speed of Motor B (0 - 100);
- `L298x L298x::setSpeed(int speed_a, int speed_b)` -  Sets the speed of the two Motors (0 - 100);
- `L298x L298x::setSpeed(int speed)` - Sets the same speed of the two Motors (0 - 100);
- `L298x L298x::fastBrakeA()` - brake Motor A, a "Fast brake";
- `L298x L298x::fastBrakeB()` - brake Motor B, a "Fast brake";
- `L298x L298x::fastBrake()` - brake Motors, a "Fast brake";
- `L298x L298x::freeBrakeA()` - brake Motor A, a "Free brake";
- `L298x L298x::freeBrakeB()` - brake Motor B, a "Free brake";
- `L298x L298x::freeBrake()` - brake Motors, a "Free brake";
- `L298x L298x::setBrakeA(int brake_a)` - Sets the standard brake of the Motor B (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298x L298x::setBrakeB(int brake_b)` - Sets the standard brake of the Motor A (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298x L298x::setBrake(int brake_a, int brake_b)` - Sets the standard brake of the two Motors (`FAST_BRAKE` or `FREE_BRAKE`);
- `L298x L298x::setBrake(int brake)` - Sets the same standard brake of the two Motors (`FAST_BRAKE` or `FREE_BRAKE`);

### You don't need to know:
- Nothing.


### Hardware Information
- The ENA and ENB pins must be connected to PWM outputs!
  More information: http://www.arduino.cc/en/Reference/analogWrite
