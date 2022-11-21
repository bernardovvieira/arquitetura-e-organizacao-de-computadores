_Simulador para uma Arquitetura Hipotética de Zero Operandos_

- Arquitetura e Organização de Computadores - 2022/2
- Bernardo Vivian Vieira (179835), Vinicius Bernardi Rebelato (109547), Yeun-Haur Kang (193593)

----- /// -------------------------------------------------------------------------------------------------------

INSTRUÇÕES PARA COMPILAÇÃO E EXECUÇÃO DO PROGRAMA

- Linguagem C++

_Linux:_

Certifique-se que você já possui o compilador g++ instalado em sua máquina, caso não, instale-o
com o comando sudo apt install g++ (distribuições Debian).

- Compile o arquivo com o comando g++ simulador.cpp -o simulador
- Execute com ./simulador

_Windows:_

A instalação, caso ainda não possua, para executar arquivos em C++ no Windows é mais complexa e
recomendamos que busque instruções detalhadas. O compilador recomendado é o MinGW. 

----- /// -------------------------------------------------------------------------------------------------------

INSTRUÇÕES DISPONÍVEIS NA ARQUITETURA

PUSHI valor 
- Insere na pilha o valor imediato especificado como operando da instrução. Exemplo: PUSHI 3.1415

PUSH endereço 
- Insere na pilha uma cópia do valor contido no endereço (hexadecimal) especificado da memória. Exemplo: PUSH 8A

POP endereço 
- Retira um valor da pilha e copia-o para endereço (hexadecimal) especificado da memória.  Exemplo: POP 8A

INPUT 
- Lê um número float do dispositivo de entrada padrão e insere-o na pilha.

PRINT 
- Retira um valor da pilha e exibe-o, em decimal, na dispositivo de saída padrão.

ADD 
- Retira dois valores da pilha (A e B, na ordem de retirada), calcula B+A  e empilha o resultado.

SUB 
- Retira dois valores da pilha (A e B, na ordem de retirada), calcula B-A  e empilha o resultado.

MUL 
- Retira dois valores da pilha (A e B, na ordem de retirada), calcula BA  e empilha o resultado.

DIV 
- Retira dois valores da pilha (A e B, na ordem de retirada), calcula B/A  e empilha o resultado.

SWAP 
- Inverte a ordem dos dois valores no topo da pilha.

DROP 
- Descarta o valor no topo da pilha

DUP 
- Insere na pilha uma cópia do atual valor no topo, ou seja, duplica na pilha o valor do topo

HLT 
- Encerra a execução do programa e sai do simulador.

----- /// -------------------------------------------------------------------------------------------------------