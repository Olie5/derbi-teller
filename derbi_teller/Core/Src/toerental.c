#include "toerental.h"

extern I2C_HandleTypeDef hi2c3;
extern uint32_t adc3_dmabuf[ADCBUF];

float32_t input_fft[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES/2];

static uint16_t fftIndex = 0;
static float ADCInput;
uint32_t ifftFlag = 0;
arm_rfft_fast_instance_f32 fft_instance;



void process_halfbuf(){
    for(uint32_t p = 0; p < (ADCBUF); p++){
        input_fft[p] = (float)adc3_dmabuf[p];
    }
    fft();
}



void fft(){
    arm_rfft_fast_init_f32(&fft_instance, TEST_LENGTH_SAMPLES);

    arm_rfft_fast_init_f32(&fft_instance, TEST_LENGTH_SAMPLES);

    arm_rfft_fast_f32(&fft_instance, input_fft, testOutput, ifftFlag);

    arm_cmplx_mag_f32(input_fft, testOutput, TEST_LENGTH_SAMPLES/2);
}


