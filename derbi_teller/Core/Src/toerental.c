#include "toerental.h"

extern I2C_HandleTypeDef hi2c3;
extern uint32_t adc3_dmabuf[ADCBUF];

float32_t input_fft[ADCBUF];
static float32_t testOutput[ADCBUF];
static float32_t output_fft_mag[ADCBUF/2];

static uint16_t fftIndex = 0;
static float ADCInput;
uint8_t ifftFlag = 0;
arm_rfft_fast_instance_f32 fft_instance;



void process_halfbuf(){
    for(uint32_t p = 0; p < (ADCBUF); p++){
        input_fft[p] = (float)adc3_dmabuf[p];
    }
   // HAL_Delay(100);
    fft();
}



void fft(){
    arm_rfft_fast_init_f32(&fft_instance, ADCBUF);

    arm_rfft_fast_f32(&fft_instance, input_fft, testOutput, ifftFlag);

    arm_cmplx_mag_f32(testOutput, output_fft_mag, ADCBUF/2);
    //arm_cmplx_mag_f32(input_fft, testOutput, TEST_LENGTH_SAMPLES/2);
}


