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
            valor_led = matrix_rgb(desenho[24 - i], desenho[24 - i], desenho[24 - i]);
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
    //Frames da animacao 2
    double* animacao_2[] = {frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9};

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 3

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 4

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 5

*/

/*
    TODO: ADICIONAR VARIAVEIS DOS FRAMES DE ANIMAÇÃO 6

*/

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
    //Funcao para aciotar animacao 2
void acionar_animacao_2(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_2, num_desenhos, valor_led, pio, sm, r, g, b, 100);
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

/*
    TODO: Funcão para acionar a animação 6

*/

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
//funcao para acender led VERMELHO no 80% (r = vermelho, g = verde, b = azul)
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

/*
    TODO:  Função para acender todos os LEDs na cor branca 
           no nível de intensidade de 20%

*/

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

        //TODO:  Substituir 'get_key()' por 'get_key()' do keypad
        char key = getchar(); 

        if (key != EOF) {
            printf("%c\n", key);
            processar_tecla(key, valor_led, pio, sm, r, g, b);
        }
        sleep_ms(10);
    }
}
