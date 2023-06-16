#include <stdio.h>
#include <cctype>
#include <vector>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "pico/cyw43_arch.h"
#include "include/morse_code.hpp"
extern "C" {
    #include "include/generalOps.h"
    #include "include/LCDops.h"
}

#define DC_BUZZER_PIN                28   // -> gpio pin of dc buzzer
#define DOT_DURATION_MS              1000 // -> duration of dot
#define DASH_DURATION_MS             3000 // -> duration of dash
#define DOT_DASH_DURATION_MS         1000 // -> duration between corresponding dots and dashes
#define CHAR_DURATION_WITHIN_WORD_MS 3000 // -> duration between characters within word
#define WORD_DURATION_MS             7000 // -> duration between words

char message[] = "Hello World!";
char init[] = "00";
char raw_instruction[] = "00001100";
int LCDpins[14] = {7, 6, 5, 4, 3, 2, 1, 0, 8, 10, 9, 16, 2};

int main()
{
    bi_decl(bi_program_description("Pico W that realys morse code through DC BUZZER"));
    stdio_init_all();

    // initalize and set DC Buzzer up
    gpio_init(DC_BUZZER_PIN);
    gpio_set_dir(DC_BUZZER_PIN, GPIO_OUT);

    // initialize LCD for usage
    for(int gpio_pin = 0; gpio_pin < 11; gpio_pin++) {
        gpio_init(LCDpins[gpio_pin]);
        gpio_set_dir(LCDpins[gpio_pin], true);
        gpio_put(LCDpins[gpio_pin], false);
    }
    LCDinit();
    LCDclear(); 
    LCDgoto(init);  
    LCDsendRawInstruction(0, 0, raw_instruction);

    for (int i = 0; message[i] != '\0'; i++) {
        std::vector<int> values = search_morse_char(message[i]);
        char temp[] = {message[i]};
        LCDwriteMessage(temp);
        for (int j = 0; j < values.size(); j++) {
            if (values[i] == 0) {
                gpio_put(DC_BUZZER_PIN, 1);
                sleep_ms(DOT_DURATION_MS);
                gpio_put(DC_BUZZER_PIN, 0);
                sleep_ms(DOT_DASH_DURATION_MS);
            }   
            else if (values[i] == 1) {
                gpio_put(DC_BUZZER_PIN, 1);
                sleep_ms(DASH_DURATION_MS);
                gpio_put(DC_BUZZER_PIN, 0);
                sleep_ms(DOT_DASH_DURATION_MS);
            }
            else if (values[i] == 3) {
                sleep_ms(WORD_DURATION_MS);
            }
        }
        sleep_ms(CHAR_DURATION_WITHIN_WORD_MS);
    }

    return 0;
}
