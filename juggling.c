#include"header.h"

char *juggling(char *arr, int N, int d)
{
	char* temp = (char *)malloc(N + 1);

	if (d > 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (i > d - 1)
				temp[i - d] = arr[i];
			else
				temp[i + (N - d)] = arr[i];
		}
		for (int i = 0; i < N; i++)
		{
			arr[i] = temp[i];
		}
		return;
	}
	else if (d < 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (i < (N - (-d)))
				temp[i + (-d)] = arr[i];
			else
				temp[i - (N - (-d))] = arr[i];
		}
		for (int i = 0; i < N; i++)
		{
			arr[i] = temp[i];
		}
		return;
	}
	return arr;
}
