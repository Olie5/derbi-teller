/**
 * @file processlayer.h
 * @author Olivier
 * @brief This file contains all the function prototypes for the display.c file
 * @date 2024-04-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

typedef struct{
    int lenght;
    int width;
    unsigned short* name;
}Bmp;

uint8_t draw_bitmap(uint16_t x_pos, uint16_t y_pos, Bmp draw);