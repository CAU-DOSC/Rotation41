#include "header.h"

void swap(char str[], int d, int a, int b)
{
  for (int i = 0; i < d; i++)
  {
    char temp = str[a + i];
    str[a + i] = str[b + i];
    str[b + i] = temp;
  }
}

char *block_swap(char str[], int n, int d)
{
  char *temp;
  
  // if(d > 0)일때는 clockwise rotation
  if (d < 0) // counterclockwise rotation
    d += n;
  
  {
    if (d == 0 || d == n)
    {
      return;
    }
    
    else if (d < n - d)
    {
      swap(str, d, 0, n - d);
      block_swap(str, n - d, d);
    }
    else
    {
      swap(str, n - d, 0, d);
      block_swap(str + n - d, d, d - (n - d));
    }
  }
  
  return str;
}
