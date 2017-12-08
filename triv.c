#include "header.h"

char *triv(char* str, int d, int n)
{
	char save_str = { 0 };
	int cnt = 0;
	if (d < 0)
	{
		d = 0 - d;
		for (int cnt = 0; cnt < d; cnt++)
		{
			save_str = str[0];

			for (int j = 0; j < n-1; j++)
			{
				str[j] = str[j + 1];
			}

			str[n - 1] = save_str;
		}
	}

	else
	{
		for (int cnt = 0; cnt < d; cnt++)
		{
			save_str = str[n - 1];

			for (int j = n - 1; j >0; j--)
			{
				str[j] = str[j - 1];
			}

			str[0] = save_str;
		}
	}
	return str;
}
