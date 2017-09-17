#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>   
#include <pthread.h> 
#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

string intStrin(int n){
	string chars = "0123456789", aux="";
	int a, b;
	a = n/10;
	b = n;
	while(n>0) {
		b = n%10;
		if(b>=0 && b<=9)
			aux += chars[b];
		n/=10;
	}
	return aux;
}

int main(int argc , char *argv[]) {
    string chars = "0123456789", aux="";
	int a, b, n=987456;
	a = n/10;
	b = n;
	while(n>0) {
		b = n%10;
		if(b>=0 && b<=9)
			aux += chars[b];
		n/=10;
	}
    cout << aux << endl;
    char str[100];
    std::size_t ptr = 0x0012FF7C;
    sprintf(str,"%p",ptr);
    cout << str << endl;
    sccanf(str,"%p",&ptr);
    cout << str << endl;

    return 0;
}

/*
void *connection_handler(void *socket_desc, void *client) {
   
    int sock = *(int*)socket_desc;
    int read_size;
    char serverReply[10000], client_cmd[5000], redirect[900], 
        redirectOut[100], redirectErr[100], 
        stOut[100], stErr[100], 
        rmOut[100]="rm ", rmErr[100]="rm ";

    string stdOut, stdErr, redStdOut = " 1> ", redStdErr = " 2> ";
    srand(time(NULL));
    stdOut = createFileName((5 + rand()%30));
    stdErr = createFileName((5 + rand()%30));
    redStdOut += stdOut;    
    redStdErr += stdErr;
   
    strcat(redirectOut, redStdOut.c_str());
    strcat(redirectErr, redStdErr.c_str());
    strcat(redirect, redirectOut);
    strcat(redirect, redirectErr);
    strcat(stOut, stdOut.c_str());
    strcat(stErr, stdErr.c_str());
    strcat(rmOut, stOut);
    strcat(rmErr, stErr);

    cout << stdOut << " " << stdErr <<" "<< redStdOut << " " << redStdErr <<" " << redirect<< endl;
    //Receive a message from client
    while( (read_size = recv(sock , client_cmd , 2000 , 0)) > 0 ) {
        
        client_cmd[read_size] = '\0';

        cout << "Client Command: " << client_cmd << endl;
       
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


string createFileName (int min_str) {

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
    return name;
}
*/