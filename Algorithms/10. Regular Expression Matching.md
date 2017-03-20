# 10. Regular Expression Matching

## 描述
实现正则表达式匹配，支持 '.' 运算和 '\*' 运算。

```
'.' 匹配任意一个字符。
'*' 匹配0次或任意次之前一个字符。

匹配应该覆盖整个输入的字符串（而不是部分）。

函数原型：
bool isMatch(const char *s，const char *p)

一些例子：
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```

## 解析
#### 1.回溯法

使用递归实现深度优先 搜索。另外，'*'号与前一个字符构成逻辑上的一个字符，注意分情况处理以及处理边界条件，具体细节见注释。

- 时间复杂度：O(n²)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    bool match(string &s,string &p,int i,int j)
    {
        // pattern已匹配完，检查字符串是否匹配完 
        if(j == p.size()) 
            return i == s.size();
        
        // pattern中，当前待匹配字符的后一个字符为'*'的情况
        if(p[j+1] == '*')
        {
            // 如果能匹配，则可以让'*'号重复0次或多重复1次；不能匹配，则让'*'号重复0次
            if((s[i] == p[j] || p[j] == '.') && i<s.size())
                return match(s,p,i,j+2) || match(s,p,i+1,j);
            return match(s,p,i,j+2);
        }
        
        // pattern中，当前待匹配字符的后一个字符不为'*'的情况    
        if(s[i] == p[j] || p[j] == '.')
            return match(s,p,i+1,j+1);
        return false;
    }
    
    bool isMatch(string s, string p) 
    {
        return match(s,p,0,0);
    }
};
```

