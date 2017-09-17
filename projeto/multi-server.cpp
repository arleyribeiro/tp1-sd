
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>   
#include <pthread.h> 
#include <bits/stdc++.h>

using namespace std;


void *connection_handler(void *);

void readFile(char *name, char *res);

char* fileName (char* fileName, int min_str );
 
int main(int argc , char *argv[]) {

    if(argc < 2) {
        printf("Usage: ./server PORT\n");
        exit (EXIT_FAILURE);
    }

    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;

    int port = atoi(argv[1]);
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
          
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;
    
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ) {
        puts("Connection accepted");
        
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0) {
            perror("could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        pthread_join( thread_id , NULL);
        puts("Handler assigned\n");
    }
     
    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }
     
    return 0;
}
 
void *connection_handler(void *socket_desc) {
   
    int sock = *(int*)socket_desc;
    int read_size;
    char serverReply[10000] , client_cmd[5000], redirect[30] = " 1>stdout.txt 2>stderr.txt";

    
    //Receive a message from client
    while( (read_size = recv(sock , client_cmd , 2000 , 0)) > 0 ) {
        
        client_cmd[read_size] = '\0';

        cout << "Client Command: " << client_cmd << endl;
       
        //concat client cmd and redirect
        strcat(client_cmd, redirect);

        int sys = system(client_cmd);
        //define which file will read
        (!sys) ? readFile("stdout.txt", serverReply) : readFile("stderr.txt", serverReply);
        
        //Send the message back to client
        write(sock , serverReply , strlen(serverReply));

        //delete file
        system("rm stdout.txt");
        system("rm stderr.txt");

        //clear the message buffer
        memset(client_cmd, 0, 5000);
        memset(serverReply, 0, 10000);
    }
     
    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("recv failed");
    }

    close(sock);
         
    return 0;
} 

void readFile(char *name, char *res) {
    int c;
    FILE *file;
    file = fopen(name, "r");
    if (file) {
        string aux;
        while ((c = getc(file)) != EOF){
            aux+=c;
        }
        strcpy(res, aux.c_str());
        fclose(file);
    }
}


char* fileName (char* fileName, int min_str ) {

    srand ( time(NULL ));
    string chars = "aLMvwxfghijbcdelmnQRSTUVFGHpqrstuIJKkyzNOP234567WXYZ01oABCSED89";
    string chars2 = "eMvwxf567WD8JKky9lmghijbcdZCSEz01RSTUVFGHpnQqrstuIoABNOP234XYaL";
    string name;

    int nt = chars.size();
    int str;
    
    str = (rand() % min_str );
    str += ( str < min_str ) ? min_str : 0;

        
    for (int i = 0; i < str; i++ ) 
        name = (rand()%2) ? name += chars[ rand() % nt ] : name += chars2[ rand() % nt ];
    name+=".txt";
    strcpy(fileName, name.c_str());
}