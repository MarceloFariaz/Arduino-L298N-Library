/*
	L298N.cpp - Implementation of methods defined on L298N.h
	
	Created by Marcelo Junio R. de Farias, April, 2015.
	Released into the public domain.
*/

#include "L298N.h"

L298N::L298N(int ENA, int IN1, int IN2, int ENB, int IN3, int IN4)
{
	_max_speed_a = 255;
	_max_speed_b = 255;
	_min_speed_a = 0;
	_min_speed_b = 0;
	_brake_a = FAST_BRAKE;
	_brake_b = FAST_BRAKE;

	_ENA = ENA;
	_IN1 = IN1;
	_IN2 = IN2;
	_ENB = ENB;
	_IN3 = IN3;
	_IN4 = IN4;
	
	pinMode(_ENA, OUTPUT);
	pinMode(_IN1, OUTPUT);
	pinMode(_IN2, OUTPUT);
	pinMode(_ENB, OUTPUT);
	pinMode(_IN3, OUTPUT);
	pinMode(_IN4, OUTPUT);
	
	digitalWrite(_ENA, LOW);
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);
	digitalWrite(_ENB, LOW);
	digitalWrite(_IN3, LOW);
	digitalWrite(_IN4, LOW);
}

L298N L298N::setMaxSpeedA(int max_speed_a)
{
	_max_speed_a = constrain(max_speed_a, 0, 255);
	
	return *this;
}

L298N L298N::setMaxSpeedB(int max_speed_b)
{
	_max_speed_b = constrain(max_speed_b, 0, 255);
	
	return *this;
}

L298N L298N::setMaxSpeed(int max_speed)
{
	setMaxSpeedA(max_speed);
	setMaxSpeedB(max_speed);
	
	return *this;
}

L298N L298N::setMaxSpeed(int max_speed_a, int max_speed_b)
{
	setMaxSpeedA(max_speed_a);
	setMaxSpeedB(max_speed_b);
	
	return *this;
}

L298N L298N::setMinSpeedA(int min_speed_a)
{
	_min_speed_a = constrain(min_speed_a, 0, 255);
	
	return *this;
}

L298N L298N::setMinSpeedB(int min_speed_b)
{
	_min_speed_b = constrain(min_speed_b, 0, 255);
	
	return *this;
}

L298N L298N::setMinSpeed(int min_speed)
{
	setMinSpeedA(min_speed);
	setMinSpeedB(min_speed);
	
	return *this;	
}

L298N L298N::setMinSpeed(int min_speed_a, int min_speed_b)
{
	setMinSpeedA(min_speed_a);
	setMinSpeedB(min_speed_b);
	
	return *this;	
}

int L298N::speedA()
{
	return _speed_a;
}

int L298N::speedB()
{
	return _speed_b;
}

L298N L298N::setSpeedA(int speed_a)
{
	speed_a = constrain(speed_a, -100, 100);
	
	_speed_a = speed_a;
	
	if (speed_a > 0)
	{
		digitalWrite(_IN1, HIGH);
		digitalWrite(_IN2, LOW);
	}
	else if (speed_a < 0)
	{
		digitalWrite(_IN1, LOW);
		digitalWrite(_IN2, HIGH);
		speed_a = -speed_a;
	}
	else 
	{
		brakeA();
	}
	
	analogWrite(_ENA, map(speed_a, 0, 100, _min_speed_a, _max_speed_a));
	
	return *this;
	
}

L298N L298N::setSpeedB(int speed_b)
{
	speed_b = constrain(speed_b, -100, 100);
	
	_speed_b = speed_b;
	
	if (speed_b > 0)
	{
		digitalWrite(_IN3, HIGH);
		digitalWrite(_IN4, LOW);
	}
	else if (speed_b < 0)
	{
		digitalWrite(_IN3, LOW);
		digitalWrite(_IN4, HIGH);
		speed_b = -speed_b;
	}
	else 
	{
		brakeB();
	}
	
	analogWrite(_ENB, map(speed_b, 0, 100, _min_speed_b, _max_speed_b));
	
	return *this;
	
}

L298N L298N::setSpeed(int speed_a, int speed_b)
{
	setSpeedA(speed_a);
	setSpeedB(speed_b);
	
	return *this;
}

L298N L298N::setSpeed(int speed)
{
	setSpeedA(speed);
	setSpeedB(speed);
	
	return *this;
}
		
L298N L298N::fastBrakeA()
{
	digitalWrite(_ENA, HIGH);
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);
	
	return *this;
}

L298N L298N::fastBrakeB()
{
	digitalWrite(_ENB, HIGH);
	digitalWrite(_IN3, LOW);
	digitalWrite(_IN4, LOW);
	
	return *this;
}

L298N L298N::fastBrake()
{
	fastBrakeA();
	fastBrakeB();
	
	return *this;
}

L298N L298N::freeBrakeA()
{
	digitalWrite(_ENA, LOW);
	return *this;
}

L298N L298N::freeBrakeB()
{
	digitalWrite(_ENB, LOW);
	
	return *this;
}

L298N L298N::freeBrake()
{
	freeBrakeA();
	freeBrakeB();
	
	return *this;
}


L298N L298N::brakeA(){
	if (_brake_a == FAST_BRAKE)
		fastBrakeA();
	if (_brake_a == FREE_BRAKE)
		freeBrakeA();
	return *this;
}

L298N L298N::brakeB(){
	if (_brake_b == FAST_BRAKE)
		fastBrakeB();
	if (_brake_b == FREE_BRAKE)
		freeBrakeB();
	return *this;
}

L298N L298N::brake(){
	brakeA();
	brakeB();

	return *this;
}

L298N L298N::setBrakeA(int brake_a)
{
	_brake_a = brake_a;
	
	return *this;
}

L298N L298N::setBrakeB(int brake_b)
{
	_brake_b = brake_b;
	
	return *this;
}

L298N L298N::setBrake(int brake_a, int brake_b)
{
	setBrakeA(brake_a);
	setBrakeB(brake_b);
	
	return *this;
}

L298N L298N::setBrake(int brake)
{
	setBrakeA(brake);
	setBrakeB(brake);
	
	return *this;
}
