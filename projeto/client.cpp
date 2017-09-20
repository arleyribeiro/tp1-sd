#include <stdio.h> 
#include <string.h>   
#include <sys/socket.h>   
#include <arpa/inet.h> 
#include <unistd.h>
#include <sys/time.h>
#include <bits/stdc++.h>

using namespace std;

void createServers(char *name, vector< pair<char*, int> > &servers);

int createSocket(int *sock); 

int main(int argc , char *argv[]) {

    //Se a quantidade de parâmetros via terminal for insuficiente
    if(argc < 2) {
        printf("[CLIENTE]: Forma de uso: ./client list_of_servers.txt\n");
        exit (EXIT_FAILURE);
    }

    int sock;
    int PORT;
    struct sockaddr_in server;
    char cmd[1000]; //Armazena-se comando obtido via terminal
    char IP[25];
    char server_reply[10000];
    string aux;
    clock_t t1; //variáveis para medir tempo de latência
    clock_t t2;
    pair<char*, int> host; //Composto de 'endereço IP' e 'porta'
    vector< pair<char*, int> > servers; //Vetor onde cada elemento possui 'endereço IP' e 'porta'
    FILE *file;  //Utilizado para ler o arquivo de servidores

    //Lê do arquivo os dados dos servidores
    file = fopen(argv[1], "r");
    if (file) {
        string aux;
        while(fscanf(file, "%s %d", IP, &PORT) != EOF){
            host.first = IP;
            host.second = PORT;
            servers.push_back(host);
        }
        fclose(file);
    }

    //Caso o comando já não tenha sido passado via terminal
	if(argc < 3) {
        printf("[CLIENTE]: Entre com o comando: ");
        getline(cin, aux);
	} else {
		aux = argv[2];
	}

    //Armazena-se e imprime comando 
    strcpy(cmd, aux.c_str());
    cout << cmd << endl;

    //Percorre-se por todos os servidores disponíveis
    for(int i=0; i<servers.size(); i++) {
        cout << "\n[CLIENTE]: Tentativa de conexão";
        cout << "\n[CLIENTE]: Endereço IP: " << servers[i].first << " Porta: " << servers[i].second << " Socket: "<< sock << endl;
        
        //Cria-se o socket
        createSocket(&sock);

        //Limpa-se estruturas
        bzero((char *) &server, sizeof(server));

        //Define-se dados da conexão
        server.sin_addr.s_addr = inet_addr( servers[i].first );
        server.sin_family = AF_INET;
        server.sin_port = htons( servers[i].second );
     
        //Tentativa de conexão com servidor remoto
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
            perror("[CLIENTE]: Conexão falhou\n");
        } else { //Se bem sucedido
         
            puts("[CLIENTE]: Conectou\n");

            t1 = clock(); //Armazena-se o tempo de início 

            //Envio de mensagem para o servidor
            if( send(sock , cmd , strlen(cmd) , 0) < 0) {
                puts("[CLIENTE]: Envio falhou");
            } else {

                //Recebe resposta do servidor
                if( recv(sock , server_reply , 2000 , 0) < 0) {
                    puts("[CLIENTE]: Falha ao executar 'recv'");
                } else {
                    //Bloco de sucesso: nada falhou!
                    t2 = clock(); //Armazena-se tempo de fim
                    
                    //Calcula-se tempo de duração da conversa
                    double timeT = (((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC);
                    cout << "[CLIENTE]: Resposta do servidor: " << server_reply << endl;
                    memset(server_reply,0,10000); //Enche o vetor server_reply com 2 mil zeros
                     
                    close(sock); //Fecha-se o socket
                    cout << "[CLIENTE]: Tempo de latência: " << timeT <<"s"<< endl;
                }
            }
        }
    }

    return 0;
}

/*não está funcionando a passagem do IP está bugada*/
void createServers(char *name, vector< pair<char*, int> > &servers) {
    char IP[25];
    char cmd[25];
    int PORT, i=0;
    pair<char*, int> host;
    FILE *file;  
    file = fopen(name, "r");
    if (file) {
        string aux;
        while(fscanf(file, "%s %d", IP, &PORT) != EOF){
            host.first = IP;
            host.second = PORT;
            servers.push_back(host);
            cout <<"[CLIENTE]: server " <<  servers[i].first << " ip " <<servers[i].second << endl;
            i++;
        }
        fclose(file);
        dup2(0, 3);
    }
}

int createSocket(int *sock) {
    
    *sock = socket(AF_INET , SOCK_STREAM , 0);
    if (*sock == -1) {
        printf("[CLIENTE]: Não foi possível criar socket");
    }
    puts("[CLIENTE]: Socket criado");
}