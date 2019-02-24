
#include<stdio.h>

// Compile with stack canary as : g++  stackCanary.c -fstack-protector-all -o yesCanary
// Compile without stack canary as : g++  stackCanary.c -o noCanary

int main( int argc,  char *argv[]){
  printf ("Stack Canary program\n");
}
