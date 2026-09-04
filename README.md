# Implementacao 3 - Escalonador de tarefas

Esta implementacao sera feita em partes, registrando erros e correcoes no arquivo `evidencias.log`.

## Parte 1 - Leitura inicial do arquivo

Nesta versao o programa ja:

- valida se o algoritmo e `rate` ou `edf`;
- abre o arquivo de entrada;
- le o tempo total da simulacao;
- le as tarefas no formato `NOME PERIODO DEADLINE BURST`;
- cria uma saida provisoria no formato `rate_dab.out` ou `edf_dab.out`;
- prepara contadores de tarefas completas, perdidas e mortas.

## Erros deixados de proposito

Estes erros existem para serem executados, registrados no `evidencias.log` e corrigidos nas proximas etapas:

- o conteudo do `.out` ainda nao e a simulacao real;
- os contadores ainda ficam zerados, porque o escalonamento ainda nao foi implementado;
- ainda nao valida arquivo malformado corretamente;
- ainda nao valida valores negativos, zero ou texto em lugar de numero;
- ainda nao valida as regras `C <= D <= P`;
- ainda nao implementa `rate`;
- ainda nao implementa `edf`.

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
cat rate_dab.out
exit
```

O comando `./scheduler fifo voo.txt` deve mostrar a primeira correcao: agora algoritmo invalido vira erro. O arquivo `rate_dab.out` ainda esta propositalmente incompleto, pois mostra apenas a leitura e contadores zerados.
