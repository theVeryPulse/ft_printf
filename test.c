#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

int main(void)
{
	char c = 'c';
	char *s = "string";
	char *ptr;
	ptr = &c;
	int d = INT_MAX;
	int c_len = printf("C  c(%c) s(%s) p(%p) d(%d)\n", c, s, s, d);
	int ft_len = ft_printf("ft c(%c) s(%s) p(%p) d(%d)\n", c, s, s, d);
	printf("Total length should be (%d), is now (%d)\n", c_len, ft_len);
}
