/*
	L298N.h - L298N header file, definition of methods and attributes.
	
	Created by Marcelo Junio R. de Farias, April, 2015.
	Released into the public domain.
*/

#ifndef L298N_h
#define L298N_h

#define FREE_BRAKE 0
#define FAST_BRAKE 1

#include <Arduino.h>

class L298N{
	private:
		int _ENA, _IN1, _IN2, _ENB, _IN3, _IN4, _speed_a, _speed_b,
			_max_speed_a, _max_speed_b, _min_speed_a, _min_speed_b;
		bool _brake_a, _brake_b;
		
	public:
		L298N (int ENA = 6, int IN1 = 7, int IN2 = 8, int ENB = 9, int IN3 = 10, int IN4 = 11);
		int speedA();
		int speedB();
		L298N setMaxSpeedA(int max_speed_a);
		L298N setMaxSpeedB(int max_speed_b);
		L298N setMaxSpeed(int max_speed_a, int max_speed_b);
		L298N setMaxSpeed(int max_speed);
		L298N setMinSpeedA(int min_speed_a);
		L298N setMinSpeedB(int min_speed_b);
		L298N setMinSpeed(int min_speed);
		L298N setMinSpeed(int min_speed_a, int min_speed_b);
		L298N setSpeedA(int speed);
		L298N setSpeedB(int speed);
		L298N setSpeed(int speed_a, int speed_b);
		L298N setSpeed(int speed);
		L298N fastBrakeA();
		L298N fastBrakeB();
		L298N fastBrake();
		L298N freeBrakeA();
		L298N freeBrakeB();
		L298N freeBrake();
		L298N brakeA();
		L298N brakeB();
		L298N brake();
		L298N setBrakeA(int brake_a);
		L298N setBrakeB(int brake_b);
		L298N setBrake(int brake_a, int brake_b);
		L298N setBrake(int brake);
};

#endif
