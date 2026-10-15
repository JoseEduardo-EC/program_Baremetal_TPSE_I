# Práticas na BeagleBone Black

1. [Sobre](#sobre)
2. [Hardware e requisitos](#hardware-e-requisitos)
3. [Estrutura do repositório](#estrutura-do-repositório)
4. [Compilação](#compilação)
5. [Team](#team)

## Sobre

Nestá disciplina aprendemos a escrever diretamente em registradores, ou sejá uma programação em Baremetal sem utilização so sistema operacional.

Este repositório reúne os exercícios práticos que tiveram foco em: 

- Manipulação de bits em registradores
- Programação na linguagém C
- Compilação cruzada (cross-compiler)
- Organização de um firmware

### Práticas realizadas
1. Hello World usando a UART. Finalidade de testar o cross-compiler
2. Ligar leds onboards e externo. Finalidade de trabalhar com GPIO OUTPUT
3. Controlar os leds com um botão. Finalidae de trabalhar com GPIO INPUT
4. Usar o temporizador da BeagleBone. Finalidad de trabalhar com os registradores de timer da BeagleBone
5. Gerar uma interrução com botão. Finalidade de trablhar com o tratamento e detcção de interrupção externa

## Hardware e requisitos
1. Sistema operacional linux
2. Palca BeagleBone Balck
3. toolchain ARM (arm-none-eabi-gcc), já incluída em toolchain/
4. Protoboard, leds, botões e resistores, cabo TTL
5. Conhecimento em C, Linux e eletrônica báscia
6. Serviddor TFTP configuradoo no host
7. Minicom instalado no host

## Estrutura do repositório

### Diretórios obrigatórios
1. src/ Código-Fonte
2. inc/ Cabeçalhos
3. Makefile Arquivo de compilação

### Diretórios que seram gerados com o make
1. obj/ Aqruivo objeto gerado na compilação
2. bin/ Binário executável

### Exemplo:
```text
TPSE_I/
|------- lab1_Hello_World/
         |--- src/
         |--- inc/
         |--- bin/
         |--- obj/
         |--- Makefile

```

## Compilação

O Makefile já copia o binario executável para a pasta do TFTP. Basta agora se comunicar com a placa via minicom:

```bash
sudo minicom
```
Aperte no botão de boot da placa ou remova o caba de força. Ao fazer isso ele irá entra no bootloader da placa (U-boot).

**Aperte espaço rapidamente antes que o kernel da placa suba para entrar no terminal do U-boot.**

### Defina o ip da placa:
```bash
setenv ipaddr 192.168.1.2
```
### Defina o ip do servidor(host):
```bash
setenv serverip 192.168.1.1
```
### Caregue o arquivo do TFTP na memória:
```bash
tftp 0x80000000 app_baremetal.bin
```
### Por último, inicialize a aplicação:
```bash
go 0x80000000 
```
## Team
- Desenvolvedor: José Eduardo
- Orientador: Prof. Dr. Francisco Helder Candido
