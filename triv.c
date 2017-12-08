#include "header.h"

char *triv(char* str, int d, int n)
{
	int cnt = 0;
	if (d < 0)
	{
		d = 0 - d;
		for (int cnt = 0; cnt < d; cnt++)
		{
			str[n - 1] = str[0];

			for (int j = 0; j < n-1; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}

	else
	{
		for (int cnt = 0; cnt < d; cnt++)
		{
			str[0] = str[n - 1];

			for (int j = n - 1; j >0; j--)
			{
				str[j] = str[j - 1];
			}
		
		}
	}
	return str;
}
