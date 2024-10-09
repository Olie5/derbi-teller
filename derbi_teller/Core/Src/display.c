#include <main.h>
#include "ssd1306.h"

/**
 * @brief draws stored bitmaps on given location
 * 
 * @param x_pos gives top left x coordinate
 * @param y_pos gives top left y coordinate
 * @param draw indicates which bitmap to draw
 * @return 0 on succes : 
 * 1 on x and y too big : 
 * 2 on x too big  : 
 * 3 on y too big  :
 * 4 on x and y too small with thickness : 
 * 5 on x too small with thickness : 
 * 6 on y too small with thickness : 
 */

uint8_t draw_bitmap(uint16_t x_pos, uint16_t y_pos, Bmp draw){

	uint16_t x = x_pos;
	uint16_t y = y_pos;
	int t = 0;

	while (x < draw.width + x_pos + 1){	//breedte van afbeelding van links naar rechts x+1 
		SSD1306_DrawPixel(x,y, SSD1306_COLOR_BLACK);
		t++;
		x++;
		if(x == draw.width + x_pos){ //als einde van rij, schuif 1 rij in pixels omlaag y+1
			y++;
			x = x_pos;
		}
		if(t == draw.width*draw.lenght) break;
	}
	return 0;
}