#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("ADC Example, measuring GPIO26\n");
    
    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);

    while (1) {
        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();

        float temp = result * conversion_factor / 0.01f;

        printf("Raw value: 0x%03x, voltage: %.2f V, temperatura: %.2f\n", result, result * conversion_factor, temp);
        sleep_ms(500);
    }
}