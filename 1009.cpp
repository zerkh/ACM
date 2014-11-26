//通过对每一个边界数值进行处理完成对pair的遍历

#include <iostream>
#include <string>
#include <cmath>
#define MAXSIZE 2000  
using namespace std;

typedef struct  PixInfo
{
  int pos;
  int code;
}Pix;

Pix inPairMap[MAXSIZE];
Pix outMap[8*MAXSIZE];

void Sort(int size);
int GetVal(int pos);
int GetCode(int pos);
void CalOutMap(int size);

int main()
{
  int size = 0;
  
  
  return 0;
}

