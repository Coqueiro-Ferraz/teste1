#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h" 


void set_LED (unsigned t)
{
    //gpio_set_level(2,!gpio_get_level(2));
    gpio_set_level(2,1);
    vTaskDelay(t);
}
void reset_LED (unsigned t)
{
    //gpio_set_level(2,!gpio_get_level(2));
    gpio_set_level(2,0);
    vTaskDelay(t);
}

void pisca_LED (unsigned t)
{
    set_LED(t);
    reset_LED(10);
}

void morse_S (void)
{
    int i;
    for(i=0;i<3;i++)
    {
        pisca_LED(30);
    }
    vTaskDelay(5);
}

void morse_O (void)
{
    int i;
    for(i=0;i<3;i++)
    {
        pisca_LED(100);
    }
    vTaskDelay(5);
}

void app_main(void)
{
    gpio_reset_pin(2);
    gpio_set_direction(2,GPIO_MODE_INPUT_OUTPUT);

    while(1)    
    {
        morse_S();
        morse_O();
        morse_S();
        vTaskDelay(30);
    }
}
