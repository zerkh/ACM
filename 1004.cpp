//水题

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double sum = 0;
  double num;
  
  while(cin >> num)
    {
      sum += num;
    }

  cout << fixed << setprecision(2) << "$" << sum/12.0 << endl;
  return 0;
}
