#include <bits/stdc++.h>
#include <unistd.h>
#define MAXN 100
using namespace std;


int main(int argc , char *argv[]) {
    char cmd[100] = "ls &> arquivo.txt";  
    int sys = system("ls 1>stdout.txt 2>stderr.txt");
     //delete file
        char rm[50]="rm ";
        (!sys) ? strcat(rm, " stdout.txt") : strcat(rm, " stderr.txt");
        
        system(rm);

    return 0;
}

