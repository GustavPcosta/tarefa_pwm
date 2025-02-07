#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

#define SERVO_PIN 22
#define LED_RGB_PIN 12

// Definir a frequência do PWM para 50Hz (período de 20ms)
#define PWM_FREQ 50
#define PWM_WRAP 20000  // Período de 20ms (50Hz) em ciclos

// Definir a frequência do PWM para o LED (1kHz)
#define LED_PWM_FREQ 1000
#define LED_PWM_WRAP 10000  // Define a resolução do ciclo ativo

// Função para configurar o PWM
void configure_pwm(uint pin, float clk_div, uint16_t wrap) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clk_div);
    pwm_config_set_wrap(&config, wrap);
    pwm_init(slice_num, &config, true);
}

// Definir o ciclo ativo do servo e aguardar o tempo especificado
void setServoPosition(uint16_t pulse_width, uint delay_ms) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
    sleep_ms(delay_ms);
}

// Definir o brilho do LED
void set_led_brightness(uint16_t duty_cycle) {
    pwm_set_gpio_level(LED_RGB_PIN, duty_cycle);
}

int main() {
    stdio_init_all();
    
    // Configurar PWM para servo e LED
    configure_pwm(SERVO_PIN, 125.0f, PWM_WRAP);
    configure_pwm(LED_RGB_PIN, 4.0f, LED_PWM_WRAP);
    
    for (int i = 0; i < 2; i++) {
        // Posição 0 graus (500µs)
        setServoPosition(400, 2000);
        
        // Posição 180 graus (2400µs)
        setServoPosition(2400, 2000);
    }
    
    // Movimento suave entre 0 e 180 graus e controle de brilho do LED
    while (1) {
        for (uint16_t pos = 400; pos <= 2400; pos += 5) {
            setServoPosition(pos, 10);
        }
        for (uint16_t pos = 2400; pos >= 400; pos -= 5) {
            setServoPosition(pos, 10);
        }

        // Aumenta o brilho do LED progressivamente
        for (uint16_t duty = 0; duty <= LED_PWM_WRAP; duty += 500) {
            set_led_brightness(duty);
            sleep_ms(50);
        }

        // Diminui o brilho do LED progressivamente
        for (uint16_t duty = LED_PWM_WRAP; duty > 0; duty -= 500) {
            set_led_brightness(duty);
            sleep_ms(50);
        }
    }
    return 0;
}
