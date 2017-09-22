/******************************************************************************************/
/** CENTRO FEDERAL DE EDUCA��O TECNOL�GICA DE MINAS GERAIS                              ***/
/** ENGENHARIA DE COMPUTA��O 					                        ***/
/** Sistemas Distribu�dos								***/
/** Prof. Anolan Barrientos								***/
/** Alunos: Arley dos Santos Ribeiro, Bruno Marques Maciel, Cassiano de Brito Andrade	***/
/** 2017-2										***/
/*******************************************************************************************

Trabalho Pr�tico 1: Comunica��o

## Ambiente de Execu��o

Desenvolveu-se o projeto na m�quina virtual VirtualBox 5.1.28 com o sistema operacional Linux mint 17.3 Cinnamon OEM (64 bits vers�o Ubuntu). O compilador utilizado foi o g++. Para instal�-lo, deve-se executar o comando abaixo no terminal.

	$ sudo apt-get install g++

## Execu��o

Para executar os servidores, deve-se rodar o comando abaixo em cada uma das m�quinas dentro do diret�rio correspondente. Deve-se substituir "porta" pelo n�mero da porta desejado.

	$ g++ multi-server.cpp -w -lpthread -o server

	$ ./server porta

Em seguida, deve-se atualizar o arquivo "servidores.txt" com o endere�o IP seguido da porta refrente � cada servidor conectado.

### Exemplo do arquivo servidores.txt com 4 servidores

192.168.1.114 8880
192.168.1.109 8881
192.168.1.110 8882
192.168.1.111 8883

Para executar o cliente, deve-se rodar o comando abaixo em uma m�quina qualquer, tomando como base que h� o arquivo �servidores.txt� em seu diret�rio atualizado. Deve-se substituir "comando_grep" pelo comando desejado. 

	$ g++ client.cpp -w -o client

	$ ./client servidores.txt comando_grep

