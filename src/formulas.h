#pragma once
#include <stdint.h>

// Bateria
float Voltage(uint8_t high, uint8_t low);
float Current(uint8_t high, uint8_t low);
int8_t TempBat(uint8_t value);
uint8_t Soc(uint8_t value);

// Motor
uint16_t RPM(uint8_t high, uint8_t low);
float Torque(uint8_t high, uint8_t low);
int8_t TempCtrl(uint8_t value);
int16_t TempMotor(uint8_t value);

// Modo
const char* Modo(uint8_t value);

//IDs
bool is_battery_msg(uint32_t id);
bool is_motor_msg(uint32_t id);