#include "speed.h"

extern I2C_HandleTypeDef hi2c1;

char speedString[10];
uint16_t speedvalue = 0;

#define SAMPLE_COUNT 1000  // Number of samples to collect
#define THRESHOLD 1000   // Threshold to detect high state

uint32_t timestamps[SAMPLE_COUNT];
uint32_t adc_samples[SAMPLE_COUNT];

void speed(uint16_t freq){
    speedvalue = freq;
    sprintf(speedString, "%d", speedvalue);
    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_GotoXY (10,10); // goto 10, 10 
    SSD1306_Puts(speedString, &Font_11x18, 1);
    SSD1306_UpdateScreen(&hi2c1);
}

void samplefreq() {
    uint32_t prev_value = 0;
    uint32_t new_value = 0;
    uint32_t start_time = HAL_GetTick();  // Start time (ms)
    int edge_count = 0;

    // Collect samples and detect rising edges
    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        HAL_ADC_Start(&hadc2);  // Start ADC conversion

        // Wait for ADC conversion to complete
        if (HAL_ADC_PollForConversion(&hadc2, 10) == HAL_OK) {
            new_value = HAL_ADC_GetValue(&hadc2);  // Read ADC value
        }
        adc_samples[i] = new_value;  // Store the sample

        // Detect rising edge
        if (new_value > THRESHOLD && prev_value <= THRESHOLD) {
            timestamps[edge_count++] = HAL_GetTick() - start_time;  // Save timestamp
            if (edge_count >= SAMPLE_COUNT) break;  // Stop if max edges reached
        }
        prev_value = new_value;
    }

    // Calculate the total time between edges
    uint32_t total_time = 0;
    for (int i = 1; i < edge_count; ++i) {
        total_time += (timestamps[i] - timestamps[i - 1]);
    }

    // Calculate the average period in ms
    float period_ms = (float)total_time / (edge_count - 1);

    // Convert period to frequency (Hz)
    float frequency = 1000.0f / period_ms;

    // Call the speed function with frequency (converted to integer)
    speed((uint16_t)frequency);

}

void calcfreq(){
    // if (timestamps[1] == 0) {  // Check if at least two edges are detected
    //     printf("Not enough edges detected!\n");
    //     return;
    // }

    // Calculate period (average time between rising edges)
    
}