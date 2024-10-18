#include "buttons.h"
extern I2C_HandleTypeDef hi2c3;


char buttonvalueString[10];
uint16_t buttonvalue = 0;

void buttons(){
    HAL_ADC_Start(&hadc1);
    buttonvalue = HAL_ADC_GetValue(&hadc1);
    sprintf(buttonvalueString, "%d", buttonvalue);
    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_GotoXY (10,10); // goto 10, 10 
    SSD1306_Puts ("Value:", &Font_11x18, 1); // print Hello 
    SSD1306_Puts(buttonvalueString, &Font_11x18, 1);
    SSD1306_GotoXY (10, 30); 
    if(buttonvalue < 100){
       SSD1306_Puts("links", &Font_11x18, 1);
    }

     else if((buttonvalue > 100) && (buttonvalue < 1000)){
       SSD1306_Puts("boven", &Font_11x18, 1);
    }

     else if((buttonvalue > 1000) && (buttonvalue < 1500)){
       SSD1306_Puts("beneden", &Font_11x18, 1);
    }

     else if((buttonvalue > 1500) && (buttonvalue < 2500)){
       SSD1306_Puts("rechts", &Font_11x18, 1);
    }

     else if((buttonvalue > 2500) && (buttonvalue < 3500)){
       SSD1306_Puts("ok", &Font_11x18, 1);
    }

     else if(buttonvalue > 3500 ){
       SSD1306_Puts("idle", &Font_11x18, 1);
    }


    SSD1306_UpdateScreen(&hi2c3); // update screen
}