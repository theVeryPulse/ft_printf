#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "libftprintf.h"

int main(void)
{
	char c = 'c';
	char *s = "string";
	int d = INT_MIN;
	unsigned int u = INT_MAX + 100;
	int c_len = printf
	(
		"C  c(%c) s(%s) p(%p) d(%d) u(%u) x(%x) X(%X)\n",
		c, s, &c, d, u, 0, INT_MAX
	);
	int ft_len = ft_printf
	(
		"ft c(%c) s(%s) p(%p) d(%d) u(%u) x(%x) X(%X)\n",
		c, s, &c, d, u, 0, INT_MAX
	);
	printf("Total length should be (%d), is now (%d)\n", c_len, ft_len);
}
