#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct DNA_Str
{
  string str;
  int val;
}DNA;

void CalVal(DNA d[], int count, int len)
{
  for(int i = 0; i < count; i++)
    {
      for(int j = 0; j < len-1; j++)
	{
	  for(int k = j+1; k < len; k++)
	    {
	      if(d[i].str[k] < d[i].str[j])
		{
		  d[i].val++;
		}
	    }
	}
    }
}

void Sort(DNA d[], int count)
{
  for(int i = 0; i < count-1; i++)
    for(int j = i+1; j < count; j++)
      {
	if(d[j].val < d[i].val)
	  {
	    DNA temp;
	    
	    temp = d[j];
	    d[j] = d[i];
	    d[i] = temp;
	  }
      }
}

int main()
{
  int length, count;
  // fstream fin("1.in");
  //streambuf *in;
  //in = cin.rdbuf(fin.rdbuf());
  
  while(cin >> length >> count)
    {
      DNA d[count];
      
      for(int i = 0; i < count; i++)
	{
	  cin >> d[i].str;
	  d[i].val = 0;
	}

      CalVal(d, count, length);
      Sort(d, count);

      for(int i = 0; i < count; i++)
	{
	  cout << d[i].str << endl;
	}
    }

  return 0;
}
