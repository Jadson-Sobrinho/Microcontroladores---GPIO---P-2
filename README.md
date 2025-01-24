# Documentação do Código

## **Descrição Geral**
O código controla uma matriz de LEDs utilizando um Raspberry Pi Pico. Ele é capaz de:
- Modularizar diferentes animações e estados da matriz.
- Configurar e manipular LEDs individualmente ou em grupo.
- Permitir controle interativo por meio de um teclado matricial (keypad).
- Acender os LEDs em diferentes cores e intensidades.

---

## **Bibliotecas Utilizadas**

### **Padrão do C**
- `<stdio.h>`: Manipulação de entrada/saída.
- `<math.h>`: Operações matemáticas.

### **Pico SDK**
- `pico/stdlib.h`: Configuração padrão para Raspberry Pi Pico.
- `hardware/pio.h`: Manipulação de entradas e saídas programáveis (PIO).
- `hardware/clocks.h`: Controle do clock do sistema.
- `hardware/adc.h`: Controle do conversor analógico-digital (ADC).
- `pico/bootrom.h`: Acesso ao bootloader.

### **Customizadas**
- `"lib/keypad.h"`: Manipulação do teclado matricial.
- `"lib/animacao_0.h"`: Frames da primeira animação.
- `"pio_matrix.pio.h"`: Configuração do PIO para controle da matriz de LEDs.

---

## **Constantes**
- `NUMERO_DE_LEDS`: Define o número de LEDs na matriz.
- `OUT_PINO`: Define o pino de saída utilizado pelo PIO.

---

## **Funções**

### **1. Manipulação de LEDs**
#### `uint32_t matrix_rgb(double r, double g, double b)`
- **Descrição**: Converte os valores de vermelho (r), verde (g), e azul (b) para um formato hexadecimal de 32 bits.
- **Parâmetros**:
  - `r`, `g`, `b`: Intensidades de vermelho, verde e azul (0.0 a 1.0).
- **Retorno**: Valor RGB no formato hexadecimal.
- **Uso**: Criação de cores para o LED.

---

#### `void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Atualiza os LEDs com base em um padrão (`desenho`), aplicando uma cor uniforme.
- **Parâmetros**:
  - `desenho`: Array com o padrão dos LEDs.
  - `valor_led`: Valor RGB.
  - `pio`: Instância do PIO.
  - `sm`: State Machine do PIO.
  - `r`, `g`, `b`: Intensidades de vermelho, verde e azul.

---

#### `void desligar_leds(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Desliga todos os LEDs da matriz.
- **Parâmetros**:
  - Mesmos de `desenho_pio`.

---

### **2. Animações**
#### `void exibir_animacao(double* animacao[], int num_desenhos, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b, int delay_ms)`
- **Descrição**: Executa uma sequência de desenhos (animação) em um intervalo de tempo.
- **Parâmetros**:
  - `animacao`: Array de ponteiros para desenhos.
  - `num_desenhos`: Quantidade de frames na animação.
  - `delay_ms`: Intervalo entre os frames.

---

#### `void acionar_animacao_0(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 0 chamando a função `exibir_animacao`.

---

### **3. Controle de Cores**
#### `void acender_azul(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Acende todos os LEDs em azul com intensidade de 100%.
- **Parâmetros**:
  - Mesmos de `desenho_pio`.

#### **Funções a Implementar (TODOs)**:
- Acender LEDs em vermelho, verde, ou branco em intensidades específicas.

---

### **4. Controle por Teclado**
#### `typedef struct { char key; void (*action)(uint32_t, PIO, uint, double, double, double); } KeyAction`
- **Descrição**: Estrutura que mapeia teclas (`key`) para funções de ação (`action`).

---

#### `KeyAction key_actions[]`
- **Descrição**: Mapeamento de teclas para ações.
- **Teclas implementadas**:
  - `'0'`: Aciona a animação 0.
  - `'A'`: Desliga os LEDs.
  - `'B'`: Acende os LEDs em azul.

---

#### `void processar_tecla(char key, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Procura uma função correspondente à tecla pressionada e a executa.
- **Comportamento padrão**: Desliga os LEDs para teclas não mapeadas.

---

### **5. Função Principal (`main`)**
- **Descrição**:
  - Configura o clock e inicializa periféricos.
  - Inicializa a matriz de LEDs desligados.
  - Entra em um loop infinito que:
    1. Lê uma tecla pressionada.
    2. Executa a função correspondente para a tecla.
- **Destaques**:
  - Inicializa o PIO com a configuração `pio_matrix`.
  - Permite controle dinâmico dos LEDs por meio do teclado.

---
