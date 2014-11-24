//难度1

#include<stdio.h>
#include<string.h>
#include<math.h>

int arr[10000000] = {0};

int main()
{
  int flag;
  int Max, Min;
  int i;
  int count;
  int k;
  int value;
  int n;
  char obj[50];
  
  flag = 0;
  Max = -1; Min = 10000001;
  fscanf(stdin, "%d", &n);
  while (n--)
    {
      fscanf(stdin, "%s", obj);
      k = strlen(obj);
      count = 6;
      value = 0;
      for (i=0; i<k; i++)
	{
	  if (obj[i]>='A' && obj[i]<='P')
	    {
	      value += (((obj[i]-'A')/3+2) * (int)(pow(10, count)));
	      count--;
	    }
	  else if (obj[i]>='Q' && obj[i]<='Y')
	    {
	      value += (((obj[i]-'Q')/3+7) * (int)(pow(10, count)));
	      count--;
	    }
	  else if (obj[i]>='0' && obj[i]<='9')
	    {
	      value += ((obj[i] - '0') * (int)(pow(10, count)));
	      count--;
	    }
	}
      arr[value]++;
      
      if (value > Max)
	{
	  Max = value;
	}
      if (value < Min)
	{
	  Min = value;
	}
    }
  for (i=Min; i<=Max; i++)
    {
      if (arr[i] > 1)
	{
	  flag = 1;
	  printf("%03d-%04d %d\n", i/10000, i%10000, arr[i]);
	}
    }
  if (!flag)
    {
      printf("No duplicates.\n");
    }

  return 0;
}



