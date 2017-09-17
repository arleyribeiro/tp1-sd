#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <unistd.h>
#include <bits/stdc++.h>


using namespace std;

int createSocket(int *sock) {
    
    *sock = socket(AF_INET , SOCK_STREAM , 0);
    if (*sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
}

int main(int argc , char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char cmd[1000] , server_reply[2000];
    string aux;
    pair<char*, int> host;
    vector< pair<char*, int> > servers;

    host.first = "127.0.0.1";
    
    //create servers
    for(int i=8880, j=0; i<8890; i++, j++) {        
        host.second = i;
        servers.push_back(host);        
    }

    while(1) {
        printf("Enter command : ");
        getline(cin, aux);

        //finish execution
        if(aux =="exit2")
            break;

        cout << aux << endl;
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
                cout << servers[i].second << endl;
                perror("Connect failed with server. Error\n");
                continue;//accepts server failure
                //return 1;
            }
             
            puts("Connected\n");
                        
            if( send(sock , cmd , strlen(cmd) , 0) < 0) {
                puts("Send failed");
                return 1;
            }

            //Receive a reply from the server
            if( recv(sock , server_reply , 2000 , 0) < 0) {
                puts("recv failed");
                break;
            }
             
            puts("Server reply :");
            cout << server_reply << endl;
            memset(server_reply,0,2000);
             
            close(sock);
        }
    }

    return 0;
}