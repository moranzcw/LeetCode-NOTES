# 8. String to Integer (atoi)

## 描述
实现atoi函数，将字符串转换为整数。

提示：仔细考虑所有可能的输入情况。如果你想挑战下自己，请不要看后面的警告，并自己考虑所有的输入用例。

注意：为了明确这个问题的细节（没有给定输入格式），您需要自己收集所有的输入格式。

更新（2015-02-10）：
C ++语言的函数签名已更新。如果您看到您的函数参数列表包含一个const char \*参数，请单击重新加载按钮重置您的代码。

警告：以下为atoi函数的要求。

atoi函数的要求：
在找到第一个非空格字符之前，该函数忽略所有的空格。然后从该字符起，由一个可能存在的正号或负号开始，后面尽可能多的数字，将其转化为数值。

当字符串中形成一个整数数字之后，后面的其他字符均被忽略，并且这些字符对此函数的执行没有影响。

如果str中的非空格字符的第一个字符不是有效的整数，或者如果不存在一个整数序列，因为str是空的或者它只包含空格字符，则不执行转换。

如果不能执行有效的转换，则返回0。如果正确的值超出可表示值的范围，则返回INT_MAX（2147483647）或INT_MIN（-2147483648）。

## 解析
- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution
{
public:
    int myAtoi(string str) 
    {
        int tempResult,result=0;
        int sign = 1;
        int i=0;
        
        while(i<str.size() && str[i]==' ')
            i++;
        
        if (str[i] == '-' || str[i] == '+') 
            sign = str[i++]=='-'? -1 : 1; 
        
        for(;i<str.size();i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                tempResult = result*10 + str[i]-'0';
                if(tempResult/10 != result)
                    return  sign>0 ? INT_MAX:INT_MIN;
                result = tempResult;
            }
            else
                break;
        }
        return result * sign;
    }
};
```

