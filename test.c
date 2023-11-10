#include <stdio.h>

int main(void)
{
	char a = 'a';
	char *ptr = &a;
	printf("%p\n", ptr);
}