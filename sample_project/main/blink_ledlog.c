#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define LED_GPIO 2   // Cambiar según tu tarjeta

static const char *TAG = "LED_APP";

void app_main(void)
{
    // Configuración del GPIO
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "Sistema iniciado correctamente");

    while (1)
    {
        // Encender LED
        gpio_set_level(LED_GPIO, 1);
        ESP_LOGI(TAG, "LED ENCENDIDO");
        ESP_LOGD(TAG, "Nivel GPIO en ALTO");
        vTaskDelay(pdMS_TO_TICKS(1000));

        // Apagar LED
        gpio_set_level(LED_GPIO, 0);
        ESP_LOGW(TAG, "LED APAGADO");
        ESP_LOGD(TAG, "Nivel GPIO en BAJO");
        vTaskDelay(pdMS_TO_TICKS(1000));

        // Ejemplo de error (simulado)
        ESP_LOGE(TAG, "Mensaje de ejemplo ERROR (simulado)");
    }
}
