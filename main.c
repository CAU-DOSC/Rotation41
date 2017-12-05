#include "header.h"

void gendata(char* str, int n);

int main()
{
  char *str;
  char *a;
  clock_t start, end;
  double time;
  int n, d;
  
  printf("Enter the string length n\n");
  scanf("%d", &n);
  printf("Enter the rotate distance d\n");
  scanf("%d", &d);
  printf("\n");
  str = (char *)malloc(sizeof(char)* (n + 1));
  a = (char *)malloc(sizeof(char)* (n + 1));
  
  if (str == NULL)
  {
    printf("Error\n");
    exit(1);
  }
  gendata(str,n);
  
  strcpy(a, str);
  //printf("처음 문자열 %s \n\n", a);
  
  start = clock();
  triv(a,d,n);
  end = clock();
  time = (double)(end - start) / CLOCKS_PER_SEC;
  //printf("trivial 문자열 출력 => %s \n", a);
  printf("trivial time : %f\n\n", time);
  
  strcpy(a,str);
  start = clock();
  juggling(a,n,d);
  end = clock();
  time = (double)(end - start) / CLOCKS_PER_SEC;
  //printf("juggling 문자열 출력 => %s \n", a);
  printf("juggling time : %f\n\n", time);
  
  strcpy(a,str);
  start = clock();
  block_swap(a,n,d);
  end = clock();
  time = (double)(end - start) / CLOCKS_PER_SEC;
  //printf("block_swap 문자열 출력 => %s \n",a);
  printf("block_swap time : %f\n\n", time);
  
  strcpy(a, str);
  start = clock();
  reversal(a,n,d);
  end = clock();
  time = (double)(end - start) / CLOCKS_PER_SEC;
  //printf("reverse 문자열 출력 => %s \n", a);
  printf("reverse time : %f\n\n", time);
  
  return 0;
}

void gendata(char* str, int n)
{
  srand(time(NULL));
  for (int i = 0; i < n; i++)
    str[i] = (rand() % 26 + 'A');
  str[n] = NULL;
}
