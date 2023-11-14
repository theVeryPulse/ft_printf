#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libftprintf.h"

int main(void)
{
	char c = 'c';
	char *s = "string";
	int c_len = printf("c(%c) s(%s)", c, s);
	int ft_len = ft_printf("c(%c) s(%s)", c, s);
	write(STDOUT_FILENO, "\n", 1);
	printf("\nTotal length should be (%d), is now (%d)\n", c_len, ft_len);
}
