#include <bits/stdc++.h>
#include <unistd.h>
#define MAXN 100
using namespace std;

void readFile(char *name, vector< pair<char*, int> > &servers) {
    char IP[25], cmd[25];
    int PORT, i=0;

    FILE *file;  
    file = fopen(name, "r");
    if (file) {
        string aux;
        while(fscanf(file, "%s %d", IP, &PORT) != EOF){
            servers.push_back(make_pair(IP, PORT));
            cout << IP << " " << PORT << endl;
        }
        fclose(file);
        dup2(0, 3);
    }
}

int main(int argc , char *argv[]) {
    char IP[25], cmd[25];
    int PORT, i=0;

    vector< pair<char*, int> > servers;
    pair<char*, int> host;
    
    readFile(argv[1], servers);
    string aux;
    cout <<"Tamanho: " << servers.size() << endl;
    printf("Enter command:");
    dup2(0,0);
    cin >> aux;
    cout << aux << endl;    
    return 0;
}
