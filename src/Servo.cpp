
#include "global.h"

Servo lock;
// A qiuick servo test that takes reads a number form 0 to 9 from the rotary encoder and maps it to the degrees the servo can turn
void unlockVault(){
        lock.write(0);
}

void lockVault(){
        lock.write(180);
}