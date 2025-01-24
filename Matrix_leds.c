#include <stdio.h>
#include "pico/stdlib.h"
#include "lib/keypad.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include <math.h>
#include "lib/animacao_boll.h"
#include "pio_matrix.pio.h"


#define NUMERO_DE_LEDS 25

//Pino de saida da matriz de leds
#define OUT_PINO 7


//rotina para definição da intensidade de cores do led
uint32_t matrix_rgb(double b, double r, double g)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

//rotina para acionar a matrix de leds - ws2812b
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int16_t i = 0; i < NUMERO_DE_LEDS; i++) {
        if (i % 2 == 0) {
            valor_led = matrix_rgb(desenho[24 - i], 0.0, 0.0);
            pio_sm_put_blocking(pio, sm, valor_led);
        } else {
            valor_led = matrix_rgb(0.0, desenho[24 - i], 0.0);
            pio_sm_put_blocking(pio, sm, valor_led);
        }
    }
}

void exibir_animacao(double* animacao[], int num_desenchos, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b, int delay_ms) {

    for (int i = 0; i < num_desenchos; i++) {

        desenho_pio(animacao[i], valor_led, pio, sm, r, g, b);
        sleep_ms(delay_ms);  // Atraso entre as animações
    
    }
   
}
    





//array dos frames da animacao da bola
double* animacao_0[] = {desenho1, desenho2, desenho3, desenho4, desenho5, desenho6, desenho7};
int num_desenhos = sizeof(animacao_0) / sizeof(animacao_0[0]);

//TODO: Adicione outras array para as animações
/*  double* animacao_1[] = {};
*   int numero_desenhos = sizeof(animacao_1) / sizeof(animacao_1[0]);
*/


int main()
{
    PIO pio = pio0; 
    bool ok;
    uint16_t i;
    uint32_t valor_led;
    double r = 0.0, b = 0.0 , g = 0.0;

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    stdio_init_all();
    

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    //Iniciação do keypad matricial
    init_keypad();

    //configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PINO);

    //inicializando a matriz de leds desligados
    desenho_pio(desenho0, valor_led, pio, sm, r, g, b); 

    while (true) {
        
        /*TODO: Troca o getchar() por get_key e captar os comando do keypad para que as condições funcionem
        * OBS: Resolver o pq não ta captando a tecla do keypad
        */


        //getchar() é para captar entrada do terminal 
        char key = getchar(); // Captura tecla não bloqueante
        printf("%c\n", key);

        switch (key)
        {
            case '0':
                exibir_animacao(animacao_0, num_desenhos, valor_led, pio, sm, r, g, b, 100);
                break;                 
            case '1':
                /*TODO: Animação 2 */
                break;
            case '2':
                /*TODO: Animação 3 */
                break;
            case '3':
                /*TODO: Animação 4 */
                break;
            case '4':
                /*TODO: Animação 5 */
                break;
            case '5':
                /* Animação 6 */
                break;
            case '6':
                /*TODO: Animação 7 */
                break;
            case '7':
                /*TOD: Animação 8 */
                break;
            case '8':
                /*TODO: Animação 9 */
                break;
            case 'A':
                desenho_pio(desenho0, valor_led, pio, sm, r, g, b); 
                break;
            case 'B':
                /*
                TODO:  Caso a tecla B seja acionada, todos os LEDs deverão ser 
                       ligados na cor azul, no nível de intensidade de 100% da 
                       luminosidade máxima.
                */
                break;
            case 'C':
                /*
                    TODO: Caso a tecla C seja acionada, todos os LEDs deverão ser 
                    ligados na cor vermelha, no nível de intensidade de 80% 
                    da luminosidade máxima.
                */
                break;
            case 'D':
                /*
                    TODO: Caso a tecla D seja acionada, todos os LEDs deverão ser 
                    ligados na cor verde, no nível de intensidade de 50% da 
                    luminosidade máxima.
                */
                break;
            case '#':
                /*
                    TODO: Caso a tecla # seja acionada, todos os LEDs deverão ser 
                    ligados na cor branca, no nível de intensidade de 20% da 
                    luminosidade máxima.
                */
                break;
            default:
                //apaga os leds caso clique em uma tecla invalida
                desenho_pio(desenho0, valor_led, pio, sm, r, g, b); 
                break;
        }
    }
}
