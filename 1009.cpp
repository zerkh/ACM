//通过对每一个边界数值进行处理完成对pair的遍历
#include <stdio.h>  
#include <cmath>  
using namespace std;
  
struct RLE  
{  
    int count;  
    int value;  
};  
struct Pos  
{  
    RLE *pixel;  
    int num;  
};  
void PrevPoint(Pos& pos)  
{  
    if(pos.num == 0){  
        pos.pixel--;  
        pos.num = pos.pixel->count - 1;  
    }else{  
        pos.num --;  
    }  
}  
void NextPoint(Pos& pos)  
{  
    if(pos.num == pos.pixel->count - 1){  
        pos.num = 0;  
        pos.pixel ++;  
    }else{  
        pos.num ++;  
    }  
}  
int GetMinimum(Pos& upper, Pos& curr, Pos& under, int i, int j, int height, int width);  
int main()  
{  
    int width, height, size;  
    RLE rle[1002];  
    Pos upper, curr, under;  
    int tmp, tmp1;  
    int i, j;  
    while(true){  
        scanf("%d", &width);  
        printf("%d\n", width);  
        if(width == 0)  
            break;  
        size = 1;  
        while(true){  
            scanf("%d%d", &rle[size].value, &rle[size].count);  
            if(rle[size].value == 0 && rle[size].count == 0)  
                break;  
            size++;  
        }  
        height = 0;  
        for(i = 1; i < size; i++){  
            height += rle[i].count;  
        }  
        height /= width;  
        rle[0].count = width;  
        rle[size].count = width;  
        RLE result = {0};  
        upper.pixel = rle;  
        upper.num = 0;  
        curr.num = 0;  
        curr.pixel = rle + 1;  
        under = curr;  
        tmp = 0;  
        while(tmp + under.pixel->count <= width){  
            tmp += under.pixel->count;  
            under.pixel++;  
        }  
        under.num = width - tmp;  
        result.value = GetMinimum(upper, curr, under, 0, 0, height, width);  
        result.count = 0;  
        for(i = 0; i < height; i++){  
            for(j = 0; j < width; j++){  
                tmp = GetMinimum(upper, curr, under, i, j, height, width);  
                if(tmp == result.value){  
                    result.count ++;  
                    if(upper.num > 0 && upper.num < upper.pixel->count - 1 &&  
                        curr.num > 0 && curr.num < curr.pixel->count - 1 &&  
                        under.num > 0 && under.num < under.pixel->count - 1){  
                            tmp = upper.pixel->count - upper.num;  
                            tmp1 = curr.pixel->count - curr.num;  
                            tmp = tmp < tmp1? tmp: tmp1;  
                            tmp1 = under.pixel->count - under.num;  
                            tmp = tmp < tmp1? tmp: tmp1;  
                            tmp -= 2;  
                            if(tmp > 0){  
                                result.count += tmp;  
                                i += tmp/width;  
                                j += tmp%width;  
                                i += j/width;  
                                j = j%width;  
                                upper.num += tmp + 1;  
                                curr.num += tmp + 1;  
                                under.num += tmp + 1;  
                                continue;  
                            }  
                    }  
                }else{  
                    printf("%d %d\n", result.value, result.count);  
                    result.value = tmp;  
                    result.count = 1;  
                }  
                NextPoint(upper);  
                NextPoint(curr);  
                NextPoint(under);  
  
            }//for j  
        }//for i  
        printf("%d %d\n0 0\n", result.value, result.count);  
    }  
    return 0;  
}  
int GetMinimum(Pos& upper, Pos& curr, Pos& under, int i, int j, int height, int width)  
{  
    Pos tmp_pos;  
    int tmp;  
    int tmp_gray = 0;  
    if(i-1 >= 0 && j - 1 >= 0){//左上  
        tmp_pos = upper;  
        PrevPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(i - 1 >= 0){//左中  
        tmp_pos = upper;  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(i - 1 >=0 && j + 1 < width){//左右  
        tmp_pos = upper;  
        NextPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(j + 1 < width){//中右  
        tmp_pos = curr;  
        NextPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(i + 1 < height && j + 1 < width){//下右  
        tmp_pos = under;  
        NextPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(i + 1 < height){//下中  
        tmp_pos = under;  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(i + 1 < height && j - 1 >= 0){//下左  
        tmp_pos = under;  
        PrevPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    if(j - 1 >= 0){//中左  
        tmp_pos = curr;  
        PrevPoint(tmp_pos);  
        tmp = abs(tmp_pos.pixel->value - curr.pixel->value);  
        if(tmp > tmp_gray)  
            tmp_gray = tmp;  
    }  
    return tmp_gray;  
}  

