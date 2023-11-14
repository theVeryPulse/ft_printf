#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libftprintf.h"

int main(void)
{
	char c = 'c';
	char *s = "string";
	char *ptr;
	ptr = &c;
	int c_len = printf("C  c(%c) s(%s) p(%p)", c, s, s);
	int ft_len = ft_printf("ft c(%c) s(%s) p(%p)", c, s, s);
	write(STDOUT_FILENO, "\n", 1);
	printf("\nTotal length should be (%d), is now (%d)\n", c_len, ft_len);
}
