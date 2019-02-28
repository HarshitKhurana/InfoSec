
#include<stdio.h>
#include<stdlib.h>

char ans[10];
void getInput() {
  gets(ans);
}

void print(){
  puts("String is : ");
  puts(ans);
}

int main( int argc,  char *argv[]){
  getInput();
  print();

}
