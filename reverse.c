#include"header.h"

void reverse(char *x, int begin, int end)
{
	char temp;

	if (begin >= end)
		return;

	temp = *(x + begin);
	*(x + begin) = *(x + end);
	*(x + end) = temp;

	reverse(x, ++begin, --end);
}

char *reversal(char *str, int n, int d)
{
	if (d > 0)
	{
		reverse(str, 0, d - 1);
		reverse(str, d, n - 1);
		reverse(str, 0, n - 1);
	}
	else
	{
		d = -d;
		reverse(str, n-d, n-1);
		reverse(str, 0, n-d-1);
		reverse(str, 0, n-1);
	}
	return str;
}
