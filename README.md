# GRUPO 6 - Subgrupo 5

---

# Relatório

**Quantidade total de membros:** 9
**Quantidade de membros participantes:** 6

## **Distribuição de tarefas**

**Líder da Semana:** *Jadson da Silva Sobrinho*

JADSON DA SILVA SOBRINHO: Configurações iniciais, Animação 0, Tecla A, Tecla B, Animação 4, Animação 5, Documentação, Vídeo Ensaio

KEVEN CHRISTIAN ALVES CÂNDIDO: Teclado matricial (wokwi), Animação 8, Tecla # Animação 7, Modo gravação

HÉRCULES SAMPAIO OLIVEIRA: Matriz de leds (wokwi), Animação 1, Tecla D

WILTON LACERDA SILVA JUNIOR: Tecla C, Animação 2

PEDRO HENRIQUE SALOMÉ PAIXÃO: Animação 3

MARLON SANTOS DE SOUZA: Animação 6


A destribuição foi baseada nas participações das atividades anteriores.
A quantidade e nível de dificuldade foi atribuida de acordo com o desempenho individual de cada um.

**Problemas encontrados**
Antemão, foram distribuidas as tarefas entre os 9 membros totais do grupo, contudo, 3 dos 9 resolveram não participar.
Sendo assim, uma restribuição foi feita entre os membros restantes e foram concluídas com excelência;

Para facilitar a implementação e manutenção futura, o código foi modularizado, contudo acabou ficando extenso
dificultando a interpretação;

Algumas pessoas acabaram ficando com mais atribuições do que planejado, então um prazo maior para entrega foi definido. 

---

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



### **2. Animações**

#### `double* animacao[] = {frame1, frame2, frame3, frame4, frame5...};`
#### `int num_desenhos = sizeof(animacao) / sizeof(animacao[0]);`

#### `void exibir_animacao(double* animacao[], int num_desenhos, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b, int delay_ms)`
- **Descrição**: Executa uma sequência de desenhos (animação) em um intervalo de tempo.
- **Parâmetros**:
  - `animacao`: Array de ponteiros para desenhos.
  - `num_desenhos`: Quantidade de frames na animaçã frames.

---

#### `void acionar_animacao_0(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 0 chamando a função `exibir_animacao`.
o.
  - `delay_ms`: Intervalo entre os
---

#### `void acionar_animacao_1(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 1 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_2(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 2 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_3(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 3 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_4(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 4 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_5(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 5 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_6(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 6 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_7(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 4 chamando a função `exibir_animacao`.

---

#### `void acionar_animacao_8(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Exibe a animação 8 chamando a função `exibir_animacao`.

---


### **3. Controle de Cores**
#### `void acender_azul(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Acende todos os LEDs em azul com intensidade de 100%.

#### `void acender_verm80(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Acende todos os LEDs em vermelho com intensidade de 80%.

#### `void ascender_verde50(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Acende todos os LEDs em verde com intensidade de 50%.

#### `void acender_branco20(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Acende todos os LEDs em branco com intensidade de 20%*:

#### `void desligar_leds(uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)`
- **Descrição**: Desliga todos os LEDs da matriz.


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

---

### **6. Fluxo do programa**

- Caso a **tecla 0** seja acionada, a animação 0 é tocada;

- Caso a **tecla 1** seja acionada, a animação 1 é tocada;

- Caso a **tecla 2** seja acionada, a animação 2 é tocada;

- Caso a **tecla 3** seja acionada, a animação 3 é tocada;

- Caso a **tecla 4** seja acionada, a animação 4 é tocada;

- Caso a **tecla 5** seja acionada, a animação 5 é tocada;

- Caso a **tecla 6** seja acionada, a animação 6 é tocada;

- Caso a **tecla 7** seja acionada, a animação 7 é tocada;

- Caso a **tecla 8** seja acionada, a animação 8 é tocada;

- Caso a **tecla A** seja acionada, todos os LEDs deverão ser 
desligados;

- Caso a **tecla B** seja acionada, todos os LEDs deverão ser 
ligados na cor azul, no nível de intensidade de 100% da 
luminosidade máxima;

- Caso a **tecla C** seja acionada, todos os LEDs deverão ser 
ligados na cor vermelha, no nível de intensidade de 80% 
da luminosidade máxima; 

- Caso a **tecla D** seja acionada, todos os LEDs deverão ser 
ligados na cor verde, no nível de intensidade de 50% da 
luminosidade máxima;

- Caso a **tecla #** seja acionada, todos os LEDs deverão ser 
ligados na cor branca, no nível de intensidade de 20% da 
luminosidade máxima.

---
