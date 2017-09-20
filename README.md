
**CENTRO FEDERAL DE EDUCAÇÃO TECNOLÓGICA DE MINAS GERAIS
ENGENHARIA DE COMPUTAÇÃO <br />
Sistemas Distribuídos <br />
Prof. Anolan Barrientos <br />
2017-2**

# Trabalho Prático 1: Comunicação

#### Arley Ribeiro <br /> Bruno Maciel <br /> Cassiano Andrade

## 1 Introdução


## 2 Desenvolvimento da aplicação


## 3 AMBIENTE DE EXECUÇÃO UTILIZADO

Desenvolveu-se o projeto na máquina virtual VirtualBox 5.1.28 com o sistema operacional Linux mint 17.3 Cinnamon OEM (64 bits versão Ubuntu). O compilador utilizado foi o g++. Para instalá-lo, deve-se executar o comando abaixo no terminal.

`$ sudo apt-get install g++`

Para executar os servidores, deve-se rodar o comando abaixo em cada uma das máquinas dentro do diretório correspondente.

`$ g++ multi-server.cpp -w -lpthread -o server`

`$ ./server 8880`

Para executar o cliente, deve-se rodar o comando abaixo em uma máquina qualquer, tomando como base que há um arquivo “servidores.txt” que possui, em cada linha, o endereço IP seguido da porta dos servidores.

`$ g++ client.cpp -w -o client`

`$ ./client servidores.txt comando_grep`

### 2.1 Servidores.txt

```
127.0.0.1 8880 
127.0.0.1 8881 
127.0.0.1 8882 
127.0.0.1 8883
127.0.0.1 8884 
```

## 4 Resultados



## Referências
