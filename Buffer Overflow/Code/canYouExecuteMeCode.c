
#include<stdio.h>
#include<stdlib.h>


void dangerousFunction()  {
  printf("GIVING SHELL\n");
  system("/bin/bash");
}

void getInput() {
  char ans[12];
  printf("String is at : %p\n",ans);
  gets(ans);
  printf("String is at : %p\n",ans);
  puts(ans);
}

int main(){
  getInput();

}
