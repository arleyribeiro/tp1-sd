#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>   
#include <pthread.h> 
#include <bits/stdc++.h>

using namespace std;

int port;

void *connection_handler(void *);

void readFile(char *name, char *res);
 
int main(int argc , char *argv[]) {

    port = atoi(argv[1]);

    if(argc < 2) {
        printf("[SERVIDOR %i]: Usage: ./server PORT\n", port);
        exit (EXIT_FAILURE);
    }

    int socket_desc , client_sock , c;
    struct sockaddr_in server , client;
     
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("[SERVIDOR %i]: Could not create socket\n", port);
    }
    printf("[SERVIDOR %i]: Socket server created\n", port);
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( port );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        //print the error message
        perror("[SERVIDOR]: bind failed. Error");
        return 1;
    }
    printf("[SERVIDOR %i]: bind done\n", port);
     
    //Listen
    listen(socket_desc , 3);
          
    //Accept and incoming connection
    printf("[SERVIDOR %i]: Waiting for incoming connections...\n", port);
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;
    
    while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ) {
        printf("[SERVIDOR %i]: Connection accepted\n", port);
        
        if( pthread_create( &thread_id , NULL ,  connection_handler , (void*) &client_sock) < 0) {
            perror("[SERVIDOR]: could not create thread");
            return 1;
        }
         
        //Now join the thread , so that we dont terminate before the thread
        pthread_join( thread_id , NULL);
        printf("[SERVIDOR %i]: Handler assigned\n", port);
    }
     
    if (client_sock < 0) {
        perror("[SERVIDOR]: accept failed");
        return 1;
    }
     
    return 0;
}
 
void *connection_handler(void *socket_desc) {
   
    int sock = *(int*)socket_desc;
    int read_size;
    char serverReply[10000] , client_cmd[5000], redirect[3000],
        redirectOut[100], redirectErr[100], 
        stOut[100], stErr[100], 
        rmOut[100]="rm ", rmErr[100]="rm ", str[100];

    /*define name file output*/
    sprintf(str,"%p",socket_desc);
    strcat(str, ".txt");//name of the file
    cout << "[SERVIDOR " << port << "]: " << str << endl;
    string aux(str);
    
    string stdOut = "stdOut-", stdErr="stdErr-", redStdOut = " 1> ", redStdErr = " 2> ";
    stdErr+=aux;
    stdOut+=aux;    
    redStdOut += stdOut;    
    redStdErr += stdErr;
  
  
    strcat(redirectOut, redStdOut.c_str());
    strcat(redirectErr, redStdErr.c_str());
    strcat(redirect, redirectOut);
    strcat(redirect, redirectErr);
    strcat(stOut, stdOut.c_str());
    strcat(stErr, stdErr.c_str());
    strcat(rmOut, stdOut.c_str());
    strcat(rmErr, stdErr.c_str());

    
    //Receive a message from client
    while( (read_size = recv(sock , client_cmd , 2000 , 0)) > 0 ) {
        
        client_cmd[read_size] = '\0';

        cout << "[SERVIDOR " << port << "]: Client Command: " << client_cmd << endl;
       
        //concat client cmd and redirect
        strcat(client_cmd, redirect);

        int sys = system(client_cmd);
        //define which file will read
        (!sys) ? readFile(stOut, serverReply) : readFile(stErr, serverReply);
        
        //Send the message back to client
        write(sock , serverReply , strlen(serverReply));

        //delete file
        system(rmOut);
        system(rmErr);

        //clear the message buffer
        memset(client_cmd, 0, 5000);
        memset(serverReply, 0, 10000);
    }
     
    if(read_size == 0) {
        printf("[SERVIDOR %i]: Client disconnected\n", port);
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("[SERVIDOR]: recv failed");
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