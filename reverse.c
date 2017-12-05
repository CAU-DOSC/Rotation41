#include"header.h"

void reverse(char *str, int begin, int end)
{
   char temp;
   int length = end - begin;
   if (!length);
   else
      length++;
   for (int i = 0; i < length / 2; i++)
   {
      temp = *(str + begin + i);
      *(str + begin + i) = *(str + end - i);
      *(str + end - i) = temp;
   }
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
