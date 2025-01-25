#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/keypad.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include <math.h>
#include "lib/animacao_0.h"
#include "lib/animacao_2.h"
#include "lib/animacao_6.h"
#include "pio_matrix.pio.h"

#define NUMERO_DE_LEDS 25
#define OUT_PINO 7

uint32_t matrix_rgb(double r, double g, double b) {
    unsigned char R, G, B;
    R = r * 255;
    G = g * 255;
    B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int16_t i = 0; i < NUMERO_DE_LEDS; i++) {
            valor_led = matrix_rgb(desenho[24 - i], 0.0, 0.0);
            pio_sm_put_blocking(pio, sm, valor_led);
    }
}

void exibir_animacao(double* animacao[], int num_desenhos, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b, int delay_ms) {
    for (int i = 0; i < num_desenhos; i++) {
        desenho_pio(animacao[i], valor_led, pio, sm, r, g, b);
        sleep_ms(delay_ms);
    }
}

// Frames da animação 0
double* animacao_0[] = {desenho1, desenho2, desenho3, desenho4, desenho5, desenho6, desenho7};
int num_desenhos = sizeof(animacao_0) / sizeof(animacao_0[0]);


/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 1

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 2
*/
    //Frames da animacao 2, por Wilton
    double* animacao_2[] = {frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9};
    int num_desenhos2 = sizeof(animacao_2) / sizeof(animacao_2[0]);

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 3

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 4

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 5

*/

// Frames da animação 6
double* animacao_6[] = {frame1_6, frame2_6, frame3_6, frame4_6, frame5_6, frame6_6, frame7_6, frame8_6, frame9_6};
int num_desenhos_6 = sizeof(animacao_6) / sizeof(animacao_6[0]);

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 7

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 8

*/



// Funcão para acionar a animação 0
void acionar_animacao_0(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_0, num_desenhos, valor_led, pio, sm, r, g, b, 100);
}

/*
    TODO: Funcão para acionar a animação 1

*/

/*
    TODO: Funcão para acionar a animação 2
*/
    //Funcao para acionar animacao 2, por Wilton
void acionar_animacao_2(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_2, num_desenhos2, valor_led, pio, sm, r, g, b, 100);
}

/*
    TODO: Funcão para acionar a animação 3

*/

/*
    TODO: Funcão para acionar a animação 4

*/

/*
    TODO: Funcão para acionar a animação 5

*/

// Função para acionar a animação 6
void acionar_animacao_6(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_6, num_desenhos_6, valor_led, pio, sm, r, g, b, 300);
}

/*
    TODO: Funcão para acionar a animação 7

*/

/*
    TODO: Funcão para acionar a animação 8

*/

void desligar_leds(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    desenho_pio(desenho0, valor_led, pio, sm, r, g, b);
}


//Acender todos os leds da matriz em azul na intensidade 100% 
void acender_azul(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUMERO_DE_LEDS; i++) {          
        valor_led = matrix_rgb(0.0, 0.0, 1.0);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}

/*
    TODO:  Função para acender todos os LEDs
           na cor vermelha, no nível de intensidade de 80% 
*/
//funcao para acender led VERMELHO no 80% (r = vermelho, g = verde, b = azul), por Wilton
void acender_verm80(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUMERO_DE_LEDS; i++) {
        valor_led = matrix_rgb(0.8, 0.0, 0.0);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}

/*
    TODO:  Função para acender todos os LEDs 
           na cor verde, no nível de intensidade de 50% 

*/


// TODO:  Função para acender todos os LEDs na cor branca no nível de intensidade de 20%
// AUTOR: Keven Christian Alves Candido

void acender_branco20(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUMERO_DE_LEDS; i++)
    {
        // branco = r,g,b iguais; intensidade 20% = 0.2
        valor_led = matrix_rgb(0.2, 0.2, 0.2);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
    
}

// Estrutura para mapeamento de teclas e ações
typedef struct {
    char key;
    void (*action)(uint32_t, PIO, uint, double, double, double);
} KeyAction;

KeyAction key_actions[] = {
    {'0', acionar_animacao_0},
    {'2', acionar_animacao_2},
    {'A', desligar_leds},
    {'B', acender_azul},
    {'C', acender_verm80},
    {'6', acionar_animacao_6},
    {'#', acender_branco20}
    //TODO: Outras teclas e ações...
};

const int num_key_actions = sizeof(key_actions) / sizeof(key_actions[0]);

// Função para processar a tecla pressionada
void processar_tecla(char key, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < num_key_actions; i++) {
        if (key_actions[i].key == key) {
            key_actions[i].action(valor_led, pio, sm, r, g, b);
            return;
        }
    }
    // Caso padrão: tecla inválida
    desligar_leds(valor_led, pio, sm, r, g, b);
}

int main() {
    PIO pio = pio0;
    uint32_t valor_led = 0;
    double r = 0.0, b = 0.0, g = 0.0;

    set_sys_clock_khz(128000, false);
    stdio_init_all();

    //Inicialização do Keypad
    init_keypad();

    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PINO);

    //Inicializa a matriz de leds desligados
    desenho_pio(desenho0, valor_led, pio, sm, r, g, b);

    while (true) {

        char key = get_key(); 

        if (key != 0) {
            printf("%c\n", key);
            processar_tecla(key, valor_led, pio, sm, r, g, b);
        }
        sleep_ms(10);
    }
}
