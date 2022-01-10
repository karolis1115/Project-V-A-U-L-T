#include "global.h"

// create a GY521 sensor object named security
GY521 IMU(0x00);

void ReadAccelerometer(float &accX, float &accY, float &accZ)
{
    IMU.read();
    accX = IMU.getAccelX();
    accY = IMU.getAccelY();
    accZ = IMU.getAccelZ();
}
