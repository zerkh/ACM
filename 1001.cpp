#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define LENGTH 200
class BigNumber 
{
private:
    int* value; 
    int decimal_bits;
    int exp;

    int previousBit(int bit) {
        if (bit < 10)
            return 0;
        else
            return bit / 10;
    }
public:
    BigNumber(char* str, int e) {
        value = new int[LENGTH];
        //decimal = new int[LENGTH];
        for(int i = 0; i < LENGTH; i++)
        {
            value[i] = 0;
            //decimal[i] = 0;
        }
        int index = -1;
        int str_len = strlen(str);
        for(int i = 0; i < str_len; i++)
            if(str[i] == '.')
                index = i;
        decimal_bits = (index == -1 ? 0 : str_len - index - 1);
        //将输入的字符串转化为相应的数值
        if (index == -1)
        {
            for (int i = 0; i < str_len; i++)
                value[LENGTH - str_len + i] = str[i] - '0';
        }
        else
        {
            for (int i = 0; i < index; i++)
                value[LENGTH - str_len + i + 1] = str[i] - '0';
            for (int i = index + 1; i < str_len; i++)
                value[LENGTH - str_len + i] = str[i] - '0';
        }
        exp = e;
    }

    ~BigNumber()
    {
        delete[] value;
    }
    void pow() {
        if (exp == 0) {
            for (int i = 0; i < LENGTH - 1; i++)
                value[i] = 0;
            value[LENGTH - 1] = 1;
            return;
        }

        int* tmp_value = new int[LENGTH];
        //int* tempDecimal = new int[LENGTH];
        for(int i = 0; i < LENGTH; i++)
            tmp_value[i] = value[i];

        for (int i = 0; i < exp - 1; i++) 
        {
            //乘一次保存一次值
            int* result_value = new int[LENGTH];

            for(int j = 0; j < LENGTH; j++)
                result_value[j] = 0;
            
            for (int j = 0; j < LENGTH; j++)
            {
                if (tmp_value[j] != 0)
                {
                    for (int k = 0; k < LENGTH; k++)
                    {
                        if (value[k] != 0)
                            result_value[j + k - LENGTH + 1] += tmp_value[j]*value[k];
                    }
                }
            }
            for (int j = 0; j < LENGTH; j++)
                value[j] = result_value[j];

            //进行进位，以防在上述相乘的过程中溢出
            for (int j = LENGTH - 1; j >=0; j--)
            {
                value[j - 1] += previousBit(value[j]);
                value[j] %=10;
            }

            delete result_value;
        }

        delete[] tmp_value;

    }

    void print()
    {
        if (exp == 0)
            printf("%d\n", 1);
        else
        {
            if (decimal_bits == 0)
            {
                bool flag = false;
                for (int i = 0; i < LENGTH; i++)
                {
                    if (value[i] == 0 && !flag)
                        continue;
                    else
                    {
                        flag = true;
                        printf("%d", value[i]);
                    }
                }
                printf("\n");
            }
            else
            {
                int bits = decimal_bits*exp;
                bool is_zero = true;
                for (int i = 0; i < LENGTH - bits; i++)
                {
                    if (value[i] == 0 && is_zero)
                        continue;
                    is_zero = false;
                    printf("%d", value[i]);
                }
                bool output_dot = false;
                int output_pos = -1;
                for (int i = LENGTH - 1; i >= LENGTH - bits; i--)
                {
                    if (value[i] == 0 && !output_dot)
                        continue;
                    output_dot = true;
                    output_pos = i;
                    break;
                }
                if (output_dot)
                {
                    printf(".");
                    for (int i = LENGTH - bits; i <=output_pos; i++)
                        printf("%d", value[i]);
                }
                printf("\n");
            }
        }
    }
};

int main() 
{
  char* str=new char[6];
  int n;
  
  while(cin>>str>>n)
    {
      BigNumber* bn = new BigNumber(str, n);
      bn->pow();
      bn->print();
      delete bn;
    }
  return 0;
}
