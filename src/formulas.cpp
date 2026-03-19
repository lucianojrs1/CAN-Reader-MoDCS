#include "formulas.h"

// IDs
static const uint32_t BATTERY_ID = 0x121;
static const uint32_t MOTOR_ID   = 0x300;

bool is_battery_msg(uint32_t id) {
    return id == BATTERY_ID;
}

bool is_motor_msg(uint32_t id) {
    return id == MOTOR_ID;
}

//BATERIA
float Current(uint16_t byte1, uint16_t byte2){
    return ((int16_t)byte1 << 8 | byte2) * 0.1f;
}

float Voltage(uint16_t byte1, uint16_t byte2){
    return ((uint16_t)byte1 << 8 | byte2) * 0.1f;
}

int8_t TempBat(uint8_t value){
    return (int8_t)value;
}

uint8_t Soc(uint8_t value) {
    return value;
}

//CONTROLADORA
uint16_t RPM(uint8_t high, uint8_t low) {
    return (high << 8) | low;
}

float Torque(uint8_t high, uint8_t low) {
    return ((int16_t)(high << 8 | low)) * 0.1f;
}

int8_t TempCtrl(uint8_t value) {
    return value - 40;
}

int16_t TempMotor(uint8_t value) {
    return value * 2;
}

//MODO
const char* Modo(uint8_t value) {
    switch(value) {
        case 0x45: return "ECO";
        case 0x4D: return "STD";
        case 0x55: return "TURBO";
        default: return "N/A";
    }
}