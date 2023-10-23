/*
 * esp32_led_7_seg.c
 *
 *  Created on: 5 thg 10, 2023
 *      Author: LEDAT
 */

#include "led_7_segs.h"

#ifdef CATHODE_CONFIG_LED_7_SEG
uint8_t led_7_seg_number[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
#endif

#ifdef ANODE_CONFIG_LED_7_SEG
uint8_t led_7_seg_number[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x4F};
#endif

uint8_t tens_digit, ones_digit;
static uint8_t led_7_seg_number_display = 0;
static uint8_t  led_7_seg_state = 0;
static uint32_t led_7_seg_ms = 0;
static uint32_t led_7_seg_ms_old = 0;
static uint32_t led_7_period_ms = 500;

static const char* TAG = "7_led_seg";

gpio_num_t led_7_segment[] = {
		LED_SEGMENT_A,
		LED_SEGMENT_B,
		LED_SEGMENT_C,
		LED_SEGMENT_D,
		LED_SEGMENT_E,
		LED_SEGMENT_F,
		LED_SEGMENT_G
};

//Config GPIO for LED 7 SEGS
void config_7segs(){
	gpio_set_direction(LED_SEGMENT_A, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_SEGMENT_B, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_SEGMENT_C, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_SEGMENT_D, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_SEGMENT_E, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED_SEGMENT_F, GPIO_MODE_OUTPUT);
}

//put into timer 1ms
void led_7_seg_1ms_elapsed(){
	led_7_seg_ms++;
	led_7_seg_application_1ms_elapsed();
}

void led_7_seg_application_1ms_elapsed(){
	if (led_7_seg_ms - led_7_seg_ms_old == (led_7_period_ms/2)){
		led_7_seg_ms_old = led_7_seg_ms;
		led_7_seg_state = !led_7_seg_state;
	}
	led_7_seg_display_number();
}

//config before setup
void led_7_seg_set_number(uint8_t number){
	led_7_seg_number_display = number;
//	ESP_LOGI(TAG, "Number have been set: %d", led_7_seg_number_display);
}

void led_7_seg_frequency_config(uint32_t frequency){
	led_7_period_ms =  1000/frequency;
	//ESP_LOGI(TAG, "Feq: %d Hz", frequency);
	//ESP_LOGI(TAG, "Period: %d ms", led_7_period_ms);
}

//led 7segs display
void led_7_seg_display_number(){

	for (uint8_t i = 0; i < 7; i++){
		gpio_set_level(led_7_segment[i], (led_7_seg_number[led_7_seg_number_display-1]<<i)&1);
	}

//	tens_digit = led_7_seg_number_display/10;
//	ones_digit = led_7_seg_number_display%10;
//
//	//display tens digit
//	if (led_7_seg_state){
//		//ESP_LOGI(TAG, "Tens digit is on");
//		for (uint8_t i = 0; i < 7; i++){
//			gpio_set_level(LED_7_SEG_1, 0);
//			gpio_set_level(led_7_segment[i], (led_7_seg_number[tens_digit-1]<<i)&1);
//		}
//	}
//
//	//display ones digit
//	if (!led_7_seg_state){
//		//ESP_LOGI(TAG, "Ones digit is on");
//		for (uint8_t i = 0; i < 7; i++){
//			gpio_set_level(LED_7_SEG_2, 0);
//			gpio_set_level(led_7_segment[i], (led_7_seg_number[ones_digit-1]<<i)&1);
//		}
//	}
}
