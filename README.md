# Implementacao 3 - Escalonador de tarefas

Esta implementacao sera feita em partes, registrando erros e correcoes no arquivo `evidencias.log`.

## Parte 1 - Inicio do programa

Nesta primeira parte o programa apenas mostra:

- o algoritmo informado;
- o nome do arquivo de entrada informado.

## Erros deixados de proposito

Estes erros existem para serem executados, registrados no `evidencias.log` e corrigidos nas proximas etapas:

- o programa ainda nao valida a quantidade de argumentos;
- o programa imprime na saida padrao;
- o programa ainda nao le o arquivo de entrada;
- o programa ainda nao cria o arquivo `.out`.

## Como registrar evidencia

```sh
script -a evidencias.log
date
whoami
pwd
make
./scheduler
./scheduler rate voo.txt
exit
```

O comando `./scheduler` sem argumentos deve mostrar o problema desta etapa. Depois vamos corrigir isso com validacao de argumentos.
