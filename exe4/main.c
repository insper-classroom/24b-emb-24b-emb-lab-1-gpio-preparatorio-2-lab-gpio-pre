#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


const int BTN_PIN_R = 28; 

const int LED_PIN_R = 5;
const int LED_PIN_P = 8; 
const int LED_PIN_B = 11;
const int LED_PIN_Y = 15; 

int main() {
  stdio_init_all();

  // configurar botao como entrada
  // lembre de ativar o pullup!

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_P);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);

  gpio_init(LED_PIN_B);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);  

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  while (true) {

    if (!gpio_get(BTN_PIN_R)) {
      while (!gpio_get(BTN_PIN_R)){}

      gpio_put(LED_PIN_R, 1);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_B, 0);
      gpio_put(LED_PIN_Y, 0);
      sleep_ms(300);

      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 1);
      gpio_put(LED_PIN_B, 0);
      gpio_put(LED_PIN_Y, 0);
      sleep_ms(300);

      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_B, 1);
      gpio_put(LED_PIN_Y, 0);
      sleep_ms(300);

      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_B, 1);
      gpio_put(LED_PIN_Y, 0);
      sleep_ms(300);   

      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_B, 0);
      gpio_put(LED_PIN_Y, 1);
      sleep_ms(300);         

      gpio_put(LED_PIN_R, 0);
      gpio_put(LED_PIN_P, 0);
      gpio_put(LED_PIN_B, 0);
      gpio_put(LED_PIN_Y, 0);
      sleep_ms(100); 
    }


  }
}