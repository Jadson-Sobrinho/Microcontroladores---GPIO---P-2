#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "lib/keypad.h" // Inclua se estiver usando a biblioteca de teclado

/**
 * Função que verifica se a tecla '*' foi pressionada e, caso positivo,
 * reinicia o Raspberry Pi Pico no modo de gravação.
 * 
 * @param key_code Código da tecla pressionada.
 */
void verificar_modo_gravacao(char key_code) {
    // Verifica se a tecla '*' foi pressionada
    if (key_code == '*') {
        printf("Tecla '*' pressionada. Habilitando modo de gravação...\n");
        
        // Reinicia o Raspberry Pi Pico no modo de gravação
        reset_usb_boot(0, 0);
    }
}
