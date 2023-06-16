#include <stdio.h>
#include <string.h>
#include <cctype>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "include/morse_code.hpp"

#define DC_BUZZER_PIN 28
char message[] = "Hello World!";

int main()
{
    stdio_init_all();

    // initalize and set DC Buzzer up
    gpio_init(DC_BUZZER_PIN);
    gpio_set_dir(DC_BUZZER_PIN, GPIO_OUT);

	

    return 0;
}
