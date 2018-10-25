class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int bit1=0,bit2=0,bitResult=0; //num1的当前运算位，num2的当前运算位，当前位运算结果
        int bit=0,carry=0;//当前位运算后的值（不含进位），当前位运算结果的进位
        
        int resultSize;//结果字符串尺寸
        //结果字符串尺寸与较大的字符串相同
        if(num1.size() > num2.size())
            resultSize = num1.size();
        else
            resultSize = num2.size();
        
        int k = resultSize-1;//结果字符串的当前位指针
        string numResult(resultSize,'0');//结果字符串
        
        int i=num1.size()-1, j=num2.size()-1;//num1的当前位指针，num2的当前位指针
        while(k>=0)
        {
            //当num1的当前位指针小于0时，说明num1以运算完成，当前位用0参与运算。
            if(i>=0)
                bit1 = num1[i]-'0';
            else
                bit1 = 0;
            
            //num2与num1同理
            if(j>=0)
                bit2 = num2[j]-'0';
            else
                bit2 = 0;
                
            bitResult = bit1 + bit2 + carry; // 当前位运算结果，包含上一次的进位
            bit = bitResult % 10; //当前位值，去掉进位
            carry = bitResult / 10; //当前位的进位
            numResult[k] = char(bit + '0');  //为结果字符串的当前位赋值
            i--;j--;k--;
        }
        // 如果结果字符串的最大位产生进位
        if(carry >0 )
            numResult = "1" + numResult;
        return numResult;
    }
};