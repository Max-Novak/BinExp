/*
Target of this program is to over flow stack in such a way that return address
from foo function is changed to bar.

Compilation command:
gcc -m32 -g -fno-stack-protector third.c -o third

Arguments used:
	-m32: instrcuting the compiler to build 32 bit Binary
	-g: This allow C code to visible in gdb
	-fno-stack-protector: Disbale stack protection by canary
*/

#include <stdio.h>

void bar()
{
    printf("How come you entered into bar ?\n");
}

void foo()
{
    char buffer[10];
    scanf("%s", buffer);
    printf("Hello ji %s \n", buffer);
}

int main()
{
    foo();
    return 0;
}

/*
Similar to 3 but now you need to find exact offset
return address --> ebp --> junk --> buffer
put bar address into return address
*/