#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bits/stdc++.h>


using namespace std;

char* fileName (char* fileName, int min_str );

int main ( void ) {
	/*string chars = "aLMvwxfghijbcdelmnQRSTUVFGHpqrstuIJKkyzNOP234567WXYZ01oABCSED89";
	int nt = chars.size();
	string name;
	int str;
	
	srand ( time(NULL ));
	str = (rand() % max_str );

	str += ( str < min_str ) ? min_str : 0;

		
	// gera string aleatória
	for (int i = 0; i < str; i++ ) {
		name += chars[ rand() % nt ];
	}

	cout<< "[*] String : " <<  name << endl;*/
	char name[50];
	fileName(name, rand()%30);
	cout << name << endl;
	return 0;
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
	
	strcpy(fileName, name.c_str());
}


