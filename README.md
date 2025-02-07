# Controle de Servo Motor e LED com Raspberry Pi Pico

## Descrição
Este projeto utiliza um Raspberry Pi Pico para controlar um servo motor e um LED RGB através do PWM (Pulse Width Modulation). O código ajusta a posição do servo motor e o brilho do LED de forma progressiva.

## Componentes Necessários
- Raspberry Pi Pico
- Servo motor (ex: SG90)
- LED RGB (ou LED comum)
- Resistores apropriados (caso necessário)
- Jumpers para conexão
- Fonte de alimentação adequada

## Funcionamento
1. O servo motor oscila suavemente entre 0° e 180°.
2. O LED aumenta e diminui seu brilho progressivamente.
3. Ambos os componentes são controlados utilizando sinais PWM configurados via GPIOs do Raspberry Pi Pico.

## Configuração dos Pinos
- **Servo Motor:** GPIO 22
- **LED RGB:** GPIO 12

## Principais Definições do Código
- **Frequência do PWM para o Servo:** 50Hz
- **Frequência do PWM para o LED:** 1kHz
- **Divisor de clock ajustado para precisão dos sinais PWM**
- **Período do PWM configurado para controle eficiente do LED e Servo**

## Como Usar
1. Conecte os componentes conforme descrito.
2. Faça upload do código para o Raspberry Pi Pico.
3. Observe o movimento do servo e a variação de brilho do LED.

## Dependências
- Biblioteca `pico/stdlib.h`
- Biblioteca `hardware/pwm.h`
- Compilador para Raspberry Pi Pico (ex: `arm-none-eabi-gcc`)

## Melhorias Futuras
- Adicionar controle via entrada analógica ou comunicação serial.
- Implementar controle de múltiplos servos.
- Adicionar uma interface de configuração para ajustes dinâmicos.

## Autor
Desenvolvido por Gustavo para aplicações em sistemas embarcados com Raspberry Pi Pico.


## Link para o vídeo
https://youtube.com/shorts/lI53DXXAKjM?feature=share
ou
https://www.canva.com/design/DAGebHZmToo/sI5a_M6Kst2DobCkcL5Szw/watch?utm_content=DAGebHZmToo&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h7b82b5a827

