
#include<stdio.h>
#include<stdlib.h>

int main( int argc,  char *argv[]){
  char *string[2] ;
  string[1] = "/bin/sh";
  string[2] = NULL;

  int s = execve(string[1] , string[2] , NULL);
  return s;

}
