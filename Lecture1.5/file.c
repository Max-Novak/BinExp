#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("ls /tmp/file.dat");
    return 0;
}

/*
If you can alter environment variables you can redirect system
calls to search in directories of your choosing
put your own binary in there renamed to something its look for and you
can redirect the program execution from ls to l337 hack
*/
