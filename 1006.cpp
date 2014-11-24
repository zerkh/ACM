//数学题 题目理解难 中国剩余定理
/*
  找出AB公倍数中除以C余1的最小的一个，乘以c
  AC公倍数中除以B余1的最小的一个，乘以b
  BC公倍数中除以C余1的最小的一个，乘以a
  三个乘积相加模最小公倍数
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int p, e, i, d;
  int n;
  int t = 1;

  while(cin >> p >> e >> i >> d && p != -1)
    {
      n = (p*5544 + e*14421 + i*1288 - d + 21252)%21252; 
      if(n == 0)
	n = 21252;
	
      cout << "Case " << t++ << ": the next triple peak occurs in " << n << " days. " << endl;
    }

  return 0;
}

