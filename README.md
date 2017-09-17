
**CENTRO FEDERAL DE EDUCAÇÃO TECNOLÓGICA DE MINAS GERAIS
ENGENHARIA DE COMPUTAÇÃO <br />
Sistemas Distribuídos <br />
Prof. Anolan Barrientos <br />
2017-2**

# Trabalho Prático 1: Comunicação

#### Arley Ribeiro <br /> Bruno Maciel <br /> Cassiano Andrade

## 1 Introdução


## 2 Desenvolvimento da aplicação

## 3 Ambiente de Execução

Para executar siga os passos abaixo:

Navegue até a pasta projeto

Execute o servidor no terminal de cada máquina com um número de porta diferente.

`$ g++ multi-server.cpp -w -lpthread -o server`

`$ ./server PORTA`

Adicione o IP e PORTA do servido em um arquivo.txt, sendo um servidor por linha.

```
127.0.0.1 8880 
127.0.0.1 8881 
127.0.0.1 8882 
127.0.0.1 8883
127.0.0.1 8884 
```

Em outro terminal execute o cliente.

`$ g++ client.cpp -o client`

`$./client lista_de_servidores.txt`

## 4 Resultados



## Referências
