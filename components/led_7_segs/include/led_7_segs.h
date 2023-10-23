/*
 * esp32_led_7_seg.h
 *
 *  Created on: 5 thg 10, 2023
 *      Author: LEDAT
 */

#ifndef MAIN_ESP32_LED_7_SEG_ESP32_LED_7_SEG_H_
#define MAIN_ESP32_LED_7_SEG_ESP32_LED_7_SEG_H_

#include <stdio.h>
#include <driver/gpio.h>
#include "esp_log.h"

#define ANODE_CONFIG_LED_7_SEG

#define LED_SEGMENT_A 12
#define LED_SEGMENT_B 13
#define LED_SEGMENT_C 14
#define LED_SEGMENT_D 15
#define LED_SEGMENT_E 16
#define LED_SEGMENT_F 17
#define LED_SEGMENT_G 18

#define LED_7_SEG_1 2
#define LED_7_SEG_2 4

void config_7segs();
void led_7_seg_set_number(uint8_t number);
void led_7_seg_display_number();
void led_7_seg_1ms_elapsed();
void led_7_seg_application_1ms_elapsed();
void led_7_seg_frequency_config(uint32_t frequency);

#endif /* MAIN_ESP32_LED_7_SEG_ESP32_LED_7_SEG_H_ */
