//水题

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  double c;

  while(cin >> c && c != 0)
    {
      n = 1;
      double sum = 0;

      while(sum<c)
	{
	  sum += 1.0/(++n);
	}

      cout << n-1 << " card(s)" << endl;
    }

  return 0;
}
