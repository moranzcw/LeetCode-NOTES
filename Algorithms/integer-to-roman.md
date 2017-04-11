# 12. Integer to Roman

## 描述
给定一个整数，将其转换为罗马数字。
假设输入数字在1到3999之间。

## 解析
比较简单但繁琐的题目，没有什么数据结构和算法，理解罗马数字的表达规则，就可以写出转换函数。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    void romanstr(string& roman, int num, char* symbol)
    {
        if(num == 0)return;
        else if(num <= 3) roman.append(num, *symbol);
        else if(num == 4)
        {
            roman.append(1,*symbol);
            roman.append(1,*(symbol+1));
        }
        else if(num <= 8)
        {
            roman.append(1,*(symbol+1));
            roman.append(num-5,*symbol);
        }
        else if(num == 9)
        {
            roman.append(1,*symbol);
            roman.append(1,*(symbol+2));
        }
    }
    
    string intToRoman(int num) 
    {
        char symbol[9] = {'I','V','X','L','C','D','M'};
        string roman="";
        int scale = 1000;
        int p=6;
        while(num)
        {
            int bit = num/scale;
            romanstr(roman, bit, symbol+p);
            num = num%scale;
            scale /= 10;
            p -= 2;
        }
        return roman;
    }
};
```

