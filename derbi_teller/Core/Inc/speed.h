#ifndef SPEED_H
#define SPEED_H

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include "main.h"
#include "arm_math.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc2;

void speed(uint16_t freq);
void samplefreq(void);
void calcfreq(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif