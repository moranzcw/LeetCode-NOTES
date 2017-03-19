# 5. Longest Palindromic Substring

## 描述
给定字符串s，找出s中最长的回文字串，你可以假设s的长度不超过1000。

**Example:**

```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
```

**Example:**

```
Input: "cbbd"

Output: "bb"
```

## 解析

分别假设每一个字符为回文子串的中心，时间复杂度为O(n)，然后以该中心向两端扩展，不断更新最长回文子串，总时间复杂度为O(n²)。
回文子串的中心可以是一个字符，也可以是两个字符，需要分开处理。

- 时间复杂度：O(n²)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int position, maxLength=0, length=0;
        for(int i=0;i<s.size();i++)
        {
            length = 1;
            for(int j=1;i+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2;
            }
        }
        
        for(int i=0;i+1<s.size();i++)
        {
            length = 0;
            for(int j=0;i+1+j<s.size()&&i-j>=0;j++)
            {
                if(s[i-j] == s[i+1+j])
                    length += 2;
                else
                    break;
            }
            if(length > maxLength)
            {
                maxLength = length;
                position = i-length/2+1;
            }
        }
        return s.substr(position,maxLength);
    }
};
```

