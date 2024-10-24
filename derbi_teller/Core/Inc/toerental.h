#ifndef TOERENTAL_H
#define TOERENTAL_H

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

#include <stdio.h>
#include "speed.h"
#include "arm_math.h"
#define TEST_LENGTH_SAMPLES 2048
#define ADCBUF 1024

void process_halfbuf();
void fft();


/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
