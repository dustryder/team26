/** Filename: game.c
 *  Author: Jacob McKenzie & Ju Feng Zhou
 *  Date: 14/10/2015
 * 	Description: A simple four-in-a-row game.
 */

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "ir_uart.h"
#include "button.h"
#include "arraycheck.h"
#include "draw.h"
#include "win_status.h"
#include "receive.h"
#include "led.h"
#include "drawcheck.h"


#define PACER_RATE 500
#define MESSAGE_RATE 20

int main(void) {
	
	button_init();
    system_init();
    navswitch_init();
    ir_uart_init();
	led_init();
    pacer_init(PACER_RATE);
    tinygl_init(PACER_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);

	tinygl_point_t pos;
	char boardGame[5][7] = {{'\0'}};
	uint8_t pwm_tick = 0;
	uint8_t state;
	uint8_t yourTurn = 0;
	uint8_t isX = 0;
	uint8_t gameActivate = 0;
	uint8_t drawn;
    pos.x = 0; 
	pos.y = 0;
	led_set(LED1, 0);
	
	check_receive(&gameActivate, &yourTurn, pos); 	
	
    while(1) {	

		tinygl_update();

        pacer_wait();
        navswitch_update();

        if (yourTurn == 1) {
			
			led_set(LED1, yourTurn);

	        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
				if (boardGame[pos.x][pos.y] == '\0') {
					tinygl_draw_point (pos, 0);
				}
				pos.x += 1;
				if (pos.x > 4) {
					pos.x = 0;
				}
				tinygl_draw_point(pos, 1);
				
			} else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
				if (boardGame[pos.x][pos.y] == '\0') {
					tinygl_draw_point (pos, 0);
				}
				pos.x -= 1;
				if (pos.x < 0) {
					pos.x = 4;
				}
				tinygl_draw_point(pos, 1);
				
			} else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
				if (boardGame[pos.x][pos.y] == '\0') {
					tinygl_draw_point(pos, 0);
				}
				pos.y += 1;
				if (pos.y > 6) {
					pos.y = 0;
				}
				tinygl_draw_point (pos, 1);
				
			} else if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
				if (boardGame[pos.x][pos.y] == '\0') {
					tinygl_draw_point(pos, 0);
				}
				pos.y -= 1;
				if (pos.y < 0) {
					pos.y = 6;
				}
				tinygl_draw_point(pos, 1);
				
			} else if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
				
				if (boardGame[pos.x][pos.y] == '\0') {
					if (isX) {
						boardGame[pos.x][pos.y] = 'X';
					} else if (!isX) {
						boardGame[pos.x][pos.y] = 'O';
					}
					
					drawn = drawCheck(boardGame);
					if (drawn == 35) {
						ir_uart_putc(pos.x);
						ir_uart_putc(pos.y);
						ir_uart_putc(2);
						ir_uart_putc(isX);
						yourTurn = 2;
						break;
					}

					ir_uart_putc(pos.x);
					ir_uart_putc(pos.y);
					ir_uart_putc(1);
					ir_uart_putc(isX);
					yourTurn = 0;
				}
			}
			
			if (arrayCheck(boardGame)) {
				break;
			}
		}
		
		led_set(LED1, yourTurn);
			
		if (yourTurn == 2) {
			break;
		}
		
		if (ir_uart_read_ready_p()) {
			pos.x = ir_uart_getc();
			pos.y = ir_uart_getc();
			yourTurn = ir_uart_getc();
			isX = (ir_uart_getc());
			if (isX) {
				boardGame[pos.x][pos.y] = 'X';
			} else {
				boardGame[pos.x][pos.y] = 'O';
			}
			isX = !isX;
		}
		
		draw(&state, boardGame, &pwm_tick);

    }
    
    led_set(LED1, 0);
	tinygl_clear();
	tinygl_update();
    win_status(yourTurn);

    return 0;
}
