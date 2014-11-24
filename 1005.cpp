#include <iostream>
#define M_PI 3.1415926
using namespace std;

int main()
{
  int n;

  cin >> n;

  for(int i = 0; i < n; i++)
    {
      double x, y;
      int year;

      cin >> x >> y;
      year = M_PI*(x*x + y*y)/100;

      cout << "Property " << i+1 << ": This property will begin eroding in year " << year+1 << "." << endl;
    }

  cout << "END OF OUTPUT." << endl;
}
