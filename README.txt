/******************************************************************************************/
/** CENTRO FEDERAL DE EDUCAÇÃO TECNOLÓGICA DE MINAS GERAIS                              ***/
/** ENGENHARIA DE COMPUTAÇÃO 					                        ***/
/** Sistemas Distribuídos								***/
/** Prof. Anolan Barrientos								***/
/** Alunos: Arley dos Santos Ribeiro, Bruno Marques Maciel, Cassiano de Brito Andrade	***/
/** 2017-2										***/
/*******************************************************************************************

Trabalho Prático 1: Comunicação

## Ambiente de Execução

Desenvolveu-se o projeto na máquina virtual VirtualBox 5.1.28 com o sistema operacional Linux mint 17.3 Cinnamon OEM (64 bits versão Ubuntu). O compilador utilizado foi o g++. Para instalá-lo, deve-se executar o comando abaixo no terminal.

	$ sudo apt-get install g++

## Execução

Para executar os servidores, deve-se rodar o comando abaixo em cada uma das máquinas dentro do diretório correspondente. Deve-se substituir "porta" pelo número da porta desejado.

	$ g++ multi-server.cpp -w -lpthread -o server

	$ ./server porta

Em seguida, deve-se atualizar o arquivo "servidores.txt" com o endereço IP seguido da porta refrente à cada servidor conectado.

### Exemplo do arquivo servidores.txt com 4 servidores

192.168.1.114 8880
192.168.1.109 8881
192.168.1.110 8882
192.168.1.111 8883

Para executar o cliente, deve-se rodar o comando abaixo em uma máquina qualquer, tomando como base que há o arquivo “servidores.txt” em seu diretório atualizado. Deve-se substituir "comando_grep" pelo comando desejado. 

	$ g++ client.cpp -w -o client

	$ ./client servidores.txt comando_grep

