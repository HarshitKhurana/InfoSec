
#include<stdio.h>
#include<string.h>

//Paste your shellcode here
unsigned char shellcode[] = "8d\x4c\x24\x04\x83\xe4\xf0\xff\x71\xfc\x55\x89\xe5\x51\x83\xec\x14\xc7\x45\xf0\xd0\x84\x04\x08\xc7\x45\xf4\x00\x00\x00\x00\x8b\x55\xf4\x8b\x45\xf0\x83\xec\x04\x6a\x00\x52\x50\xe8\xb4\xfe\xff\xff\x83\xc4\x10\x89\x45\xf4\x8b\x45\xf4\x8b\x4d\xfc\xc9\x8d\x61\xfc\xc3\x66\x90\x90";

int main(){

	int (*shellcode_ptr)() = ( int(*)()) shellcode ; 
	printf(" Length of shellcode is : %d \n"  , strlen(shellcode_ptr));
	int x = shellcode_ptr();
	printf(" Return value of shellcode is : %d \n"  , x );

	return 0;
}