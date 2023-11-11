#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libftprintf.h"

int main(void)
{
	int c_len = printf("abcd%c %s", 'A', "string");
	int ft_len = ft_printf("abcd%c %s", 'A', "string");
	write(STDOUT_FILENO, "\n", 1);
	printf("\tTotal length should be (%d), is now (%d)\n", c_len, ft_len);
}