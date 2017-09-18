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

    if(argc < 2) {
        printf("Usage: ./client list_of_servers.txt\n");
        exit (EXIT_FAILURE);
    }

    int sock, PORT;
    struct sockaddr_in server;
    char cmd[1000], IP[25], server_reply[10000];
    string aux;
    clock_t t1, t2;
    pair<char*, int> host;
    vector< pair<char*, int> > servers; //servers that will connected

    //read servers of the file
    FILE *file;  
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

    while(1) {
        printf("Enter command : ");
        getline(cin, aux);

        //finish execution
        if(aux =="exit2")
            break;

        strcpy(cmd, aux.c_str());
        cout << cmd << endl;

        //connect with servers avaliables
        for(int i=0; i<servers.size(); i++) {
            cout << "\nServer ip: " << servers[i].first << " port: " << servers[i].second << " sock: "<< sock << endl;
            
            //Create socket
            createSocket(&sock);

            //clear structs
            bzero((char *) &server, sizeof(server));

            server.sin_addr.s_addr = inet_addr( servers[i].first );
            server.sin_family = AF_INET;
            server.sin_port = htons( servers[i].second );
         
            //Connect to remote server
            if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
                perror("Connect failed with server. Error\n");
                //continue;//accepts server failure
                return 1;
            }
             
            puts("Connected\n");
            
            t1 = clock();
            if( send(sock , cmd , strlen(cmd) , 0) < 0) {
                puts("Send failed");
                return 1;
            }

            //Receive a reply from the server
            if( recv(sock , server_reply , 2000 , 0) < 0) {
                puts("recv failed");
                break;
            }
            t2 = clock();
            
            double timeT = (((double)t2 - (double)t1)/(double)CLOCKS_PER_SEC);
            puts("Server reply :");
            cout << server_reply << endl;
            memset(server_reply,0,2000);
             
            close(sock);
            cout << "Latency time: " << timeT <<"s"<< endl;
        }
    }

    return 0;
}

/*não está funcionando a passagem do IP está bugada*/
void createServers(char *name, vector< pair<char*, int> > &servers) {
    char IP[25], cmd[25];
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
            cout <<"server " <<  servers[i].first << " ip " <<servers[i].second << endl;
            i++;
        }
        fclose(file);
        dup2(0, 3);
    }
}

int createSocket(int *sock) {
    
    *sock = socket(AF_INET , SOCK_STREAM , 0);
    if (*sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
}