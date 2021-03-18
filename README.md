# Controle de Caldeira

Este repositorio tem por fins hospedar a base de codido do trabalho da disciplina de Software em Tempo Real da UFC Sobral 2020.2 (SBL0092). O qual se trata de um software para controle em tempo real de uma caldeira.

A base de codigo esta dividida da seguinte forma:

`src` são onde todos os codigos fontes foram escritos
`inc` são onde todos os cabeçalhos se encontram
`bin` é o diretório onde o executavél ira ser gerado
`obj` é o diretório resposavél por armazenar os codigos compilados

os arquivos `.clang-format`, `.editorconfig` são para manter a coerencia no estilo do projeto, ja que o mesmo foi desenvolvido por diversos programadores.

# Compilação e Execução

Para facilitar o processo de compilação e execução estamos unsando o `make`, seu uso é bem simples, separamos alguns comandos, que estao listados abaixo

`make dev` - Limpa os arquivos previamentes compilados e o executavél (se houverem), compila e executa o programa

`make` - Compila o programa

`make run`- Executa o programa

`make clean` - Limpa os arquivos compilados e o executavél (caso existam)

Exemplo de execução:

    $ make
    $ make run


OBS: No arquivo Makefile, esta definida uma varivél de ambiente chamada ARGS, que são os argumentos que serão passados ao programa, caso não queria modificar o arquivo podera fazer da seguinte forma:

    $ make run ARGS="ip porta"

Onde o IP é o endereço de onde o simulador esta exeutando e a porta é a mesma porta definida no simulador. (A porta padrão é 4545)

# Padrão de projeto

Utilizamos algo baseado na divisão para conquistar, e tentanmos ao maximo separar as responsabilidades do programa em submodulos, que foram dividos em varios aqruivos diferentes.
Temos o arquivo `main.c` que é responsavél por agregar todos as outras funções definidas, e executar o programa.
Temos os arquivos `sensor.c` e `atuator.c` que tem como responsabilidade encapsular a comunicaçao entre o socket para abstarir o uso do sensores e atuadores nas demais funções como meramente variavéis.
O codigo presente em `tasks.c` são todas as tarefas que o programa ira executar.
Os demais arquvios são funçoes auxiliares, como pro exemplo o arquivo `util.c` que contem funçoes e definiçoes usadas em todo o projeto, como também o arquivo `buffer.c` que define o buffer duplo para armazenamento dos dados em disco.

