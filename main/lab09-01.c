#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// กำหนดขา GPIO ที่ต่อ LED จริง ๆ
#define LED1_GPIO 2
#define LED2_GPIO 0
#define LED3_GPIO 4

void app_main(void)
{
    gpio_set_direction(LED1_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED2_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED3_GPIO, GPIO_MODE_OUTPUT);

    while(1)
    {
        gpio_set_level(LED1_GPIO, 1);
        gpio_set_level(LED2_GPIO, 0);
        gpio_set_level(LED3_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED1_GPIO, 0);
        gpio_set_level(LED2_GPIO, 1);
        gpio_set_level(LED3_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED1_GPIO, 0);
        gpio_set_level(LED2_GPIO, 0);
        gpio_set_level(LED3_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
