# 9. Palindrome Number

## 描述
判断一个整数是否是回文，并且不使用额外空间。

## 解析
将数字翻转，然后与原数字比对前一半数位即可。注意分别处理奇数个数位和偶数个数位的情况。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;
        if(x==0) return true;
        if(x%10==0) return false;
        
        int reverse=0;
        while(x>reverse)
        {
            reverse = reverse*10+x%10;
            x = x/10;
        }
        return (x==reverse)||(x==reverse/10);
    }
};
```

