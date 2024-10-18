#include "speed.h"

extern I2C_HandleTypeDef hi2c1;

char speedString[10];
uint16_t speedvalue = 0;

uint16_t buttonvalue1 = 0;

void speed(){
    HAL_ADC_Start(&hadc2);
    speedvalue = HAL_ADC_GetValue(&hadc2);
    sprintf(speedString, "%d", speedvalue);
    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_GotoXY (10,10); // goto 10, 10 
    SSD1306_Puts ("Value:", &Font_11x18, 1); // print Hello 
    SSD1306_Puts(speedString, &Font_11x18, 1);

    buttonvalue1 = HAL_ADC_GetValue(&hadc1);
    SSD1306_GotoXY (10, 30); 
    if(buttonvalue1 < 100){
       SSD1306_Puts("links", &Font_11x18, 1);
    }

     else if((buttonvalue1 > 100) && (buttonvalue1 < 1000)){
       SSD1306_Puts("boven", &Font_11x18, 1);
    }

     else if((buttonvalue1 > 1000) && (buttonvalue1 < 1500)){
       SSD1306_Puts("beneden", &Font_11x18, 1);
    }

     else if((buttonvalue1 > 1500) && (buttonvalue1 < 2500)){
       SSD1306_Puts("rechts", &Font_11x18, 1);
    }

     else if((buttonvalue1 > 2500) && (buttonvalue1 < 3500)){
       SSD1306_Puts("ok", &Font_11x18, 1);
    }

     else if(buttonvalue1 > 3500 ){
       SSD1306_Puts("idle", &Font_11x18, 1);
    }


    SSD1306_UpdateScreen(&hi2c1); 
}