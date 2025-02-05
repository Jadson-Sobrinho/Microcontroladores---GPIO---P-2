#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/keypad.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include <math.h>
#include "lib/animacao_0.h"
#include "lib/animacao_1.h"
#include "lib/animacao_2.h"
#include "lib/animacao_3.h"
#include "lib/animacao_4.h"
#include "lib/animacao_5.h"
#include "lib/animacao_6.h"
#include "lib/animacao_8.h"
#include "lib/animacao_7.h"
#include "lib/modo_gravacao.c"
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
double* animacao_0[] = {desenho1, desenho2, desenho3, desenho4, desenho5, desenho6, desenho7, desenho8, desenho9, desenho10, desenho11, desenho12, desenho13, desenho14, desenho15, desenho16, desenho17, desenho18, desenho19, desenho20, desenho21, desenho22, desenho23, desenho24};
int num_desenhos = sizeof(animacao_0) / sizeof(animacao_0[0]);


// Frames da animacao 1
double* animacao_1[] = {frame_1_1, frame_1_2, frame_1_3, frame_1_4, frame_1_5, frame_1_6, frame_1_7};
int num_frames = sizeof(animacao_1) / sizeof(animacao_1[0]);


//Frames da animacao 2, por Wilton
double* animacao_2[] = {frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8, frame9};
int num_desenhos2 = sizeof(animacao_2) / sizeof(animacao_2[0]);

//Variaveis da animacao 3
double* animacao_3[] = {frame00, frame01, frame02, frame03, frame04, frame05, frame06, frame07, frame08, frame09};
int num_desenhos3 = sizeof(animacao_3) / sizeof(animacao_3[0]);

//Variveis da animação 4
double* animacao_4[] = {desenho1_1, desenho2_2, desenho3_3, desenho4_4, desenho5_5, desenho6_6, desenho7_7, desenho8_8, desenho9_9, desenho10_10, desenho11_11, desenho12_12, desenho13_13, desenho14_14, desenho15_15, desenho16_16, desenho17_17, desenho18_18, desenho19_19, desenho20_20, desenho21_21, desenho22_22, desenho23_23, desenho24_24};
int num_desenhos_4 = sizeof(animacao_4) / sizeof(animacao_4[0]);

//Variaveis da animação 5
double* animacao_5[] = {quadro0, quadro1, quadro2, quadro3, quadro4, quadro5, quadro6, quadro7, quadro8, quadro9, quadro10, quadro11, quadro12, quadro13, quadro14, quadro15, quadro16, quadro17, quadro18, quadro19, quadro20, quadro21};
int num_desenhos_5 = sizeof(animacao_5) / sizeof(animacao_5[0]);

//Frames da animação 6
double* animacao_6[] = {frame1_6, frame2_6, frame3_6, frame4_6, frame5_6, frame6_6, frame7_6, frame8_6, frame9_6};
int num_desenhos_6 = sizeof(animacao_6) / sizeof(animacao_6[0]);

//Frames da animação 7
// AUTOR: KEVEN CHRISTIAN ALVES CANDIDO
double* animacao_7[] = {frame1_7, frame2_7, frame3_7, frame4_7, frame5_7, frame6_7};
int num_desenhos_7 = sizeof(animacao_7) / sizeof(animacao_7[0]);


// AUTOR: KEVEN CHRISTIAN ALVES CANDIDO
double* animacao_8[] = {frame1_8, frame2_8, frame3_8, frame4_8, frame5_8, frame6_8};
int num_desenhos_8 = sizeof(animacao_8) / sizeof(animacao_8[0]);


// Funcão para acionar a animação 0
void acionar_animacao_0(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_0, num_desenhos, valor_led, pio, sm, r, g, b, 100);
}

// Funcao para acionar a animacao 1
void acionar_animacao_1(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b){
    exibir_animacao(animacao_1, num_frames, valor_led, pio, sm, r, g, b, 100);
}

//Funcao para acionar animacao 2, por Wilton
void acionar_animacao_2(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_2, num_desenhos2, valor_led, pio, sm, r, g, b, 100);
}

void acionar_animacao_3(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_3, num_desenhos3, valor_led, pio, sm, r, g, b, 100);
}

// Função para acionar a animação 4
void acionar_animacao_4(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_4, num_desenhos_4, valor_led, pio, sm, r, g, b, 100);
}

// Funcão para acionar a animação 5
void acionar_animacao_5(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_5, num_desenhos_5, valor_led, pio, sm, r, g, b, 600);
}

// Função para acionar a animação 6
void acionar_animacao_6(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_6, num_desenhos_6, valor_led, pio, sm, r, g, b, 100);
}

// Função para acionar a animação 7
// AUTOR: KEVEN CHRISTIAN ALVES CANDIDO
void acionar_animacao_7(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_7, num_desenhos_7, valor_led, pio, sm, r, g, b, 100);
}

// AUTOR: KEVEN CHRISTIAN ALVES CANDIDO
void acionar_animacao_8(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    exibir_animacao(animacao_8, num_desenhos_8, valor_led, pio, sm, r, g, b, 300);
}

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


//funcao para acender led VERMELHO no 80% (r = vermelho, g = verde, b = azul), por Wilton
void acender_verm80(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUMERO_DE_LEDS; i++) {
        valor_led = matrix_rgb(0.8, 0.0, 0.0);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}


// AUTOR: Hercules Sampaio Oliveira
void ascender_verde50(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b){
    for(int i=0; i<NUMERO_DE_LEDS; i++){
        valor_led = matrix_rgb(0.0, 0.5, 0.0);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}


// AUTOR: Keven Christian Alves Candido

void acender_branco20(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUMERO_DE_LEDS; i++)
    {
        // branco = r,g,b iguais; intensidade 20% = 0.2
        valor_led = matrix_rgb(0.2, 0.2, 0.2);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
    
}

void habilitar_modo_gravacao(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    printf("Tecla '*' pressionada. Habilitando modo de gravação...\n");

    // Reinicia o Pico no modo USB para gravação
    reset_usb_boot(0, 0);
}

// Estrutura para mapeamento de teclas e ações
typedef struct {
    char key;
    void (*action)(uint32_t, PIO, uint, double, double, double);
} KeyAction;

KeyAction key_actions[] = {
    {'0', acionar_animacao_0},
    {'1', acionar_animacao_1},
    {'2', acionar_animacao_2},
    {'3', acionar_animacao_3},
    {'4', acionar_animacao_4},
    {'5', acionar_animacao_5},
    {'6', acionar_animacao_6},
    {'7', acionar_animacao_7},
    {'8', acionar_animacao_8},
    {'A', desligar_leds},
    {'B', acender_azul},
    {'C', acender_verm80},
    {'D', ascender_verde50},
    {'#', acender_branco20},
    {'*', habilitar_modo_gravacao},
    
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
            // Itera sobre o mapeamento de teclas e ações
            for (int i = 0; i < sizeof(key_actions) / sizeof(KeyAction); i++) {
                if (key_actions[i].key == key) {
                    // Executa a ação correspondente à tecla pressionada
                    key_actions[i].action(valor_led, pio, sm, r, g, b);
                    break;
                }
            }
        }
        sleep_ms(10);
    }
}
