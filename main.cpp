#include <stdio.h>
#include <cctype>
#include <vector>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "include/morse_code.hpp"

#define DC_BUZZER_PIN                28   // -> gpio pin of dc buzzer
#define DOT_DURATION_MS              1000 // -> duration of dot
#define DASH_DURATION_MS             3000 // -> duration of dash
#define DOT_DASH_DURATION_MS         1000 // -> duration between corresponding dots and dashes
#define CHAR_DURATION_WITHIN_WORD_MA 3000 // -> duration between characters within word
#define WORD_DURATION_MS             7000 // -> duration between words

char message[] = "test";

int main()
{
    stdio_init_all();

    // initalize and set DC Buzzer up
    gpio_init(DC_BUZZER_PIN);
    gpio_set_dir(DC_BUZZER_PIN, GPIO_OUT);

    for (int i = 0; message[i] != '\0'; i++) {
        std::vector<int> values = search_morse_char(message[i]);
        for (int j = 0; j < values.size(); j++) {
            if (values[i] == 0) {
                gpio_put(DC_BUZZER_PIN, 1);
                sleep_ms(DOT_DASH_DURATION_MS);
                gpio_put(DC_BUZZER_PIN, 0);
                sleep_ms(DOT_DASH_DURATION_MS);
            }
            else if (values[i] == 1) {
                gpio_put(DC_BUZZER_PIN, 1);
                sleep_ms(DASH_DURATION_MS);
                gpio_put(DC_BUZZER_PIN, 0);
                sleep_ms(DOT_DASH_DURATION_MS);
            }
            else if (message[i] == ' ') {
                gpio_put(DC_BUZZER_PIN, 1);
                sleep_ms(7000);
                gpio_put(DC_BUZZER_PIN, 0);
            }
        }
    }

    return 0;
}
