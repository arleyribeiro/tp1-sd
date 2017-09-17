#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bits/stdc++.h>


using namespace std;

/* sscanf example */
#include <stdio.h>

int main ()
{
  char sentence []="Rudolph is 12 years old";
  char str [20];
  int i;
  size_t ptr = 0x7fff4c851bf8;

  sscanf(str,"%p",&ptr);
  sscanf (str,"%p",&ptr);
  cout << str << endl;
  
  return 0;
}

