# Implementacao 3 - Escalonador de tarefas

Esta implementacao sera feita em partes, registrando erros e correcoes no arquivo `evidencias.log`.

## Parte 1 - Leitura inicial do arquivo

Nesta primeira parte o programa:

- o algoritmo informado;
- abre o arquivo de entrada;
- le o tempo total da simulacao;
- le as tarefas no formato `NOME PERIODO DEADLINE BURST`;
- mostra as tarefas lidas no terminal.

## Erros deixados de proposito

Estes erros existem para serem executados, registrados no `evidencias.log` e corrigidos nas proximas etapas:

- o programa imprime na saida padrao;
- mensagens de erro ainda usam `printf`, nao `stderr`;
- ainda nao valida se o primeiro argumento e somente `rate` ou `edf`;
- ainda nao valida arquivo malformado corretamente;
- ainda nao valida valores negativos, zero ou texto em lugar de numero;
- ainda nao valida as regras `C <= D <= P`;
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
./scheduler fifo voo.txt
exit
```

O comando `./scheduler fifo voo.txt` deve mostrar que o algoritmo invalido ainda nao esta sendo tratado como erro real. Depois vamos corrigir isso.
