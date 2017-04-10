# 22. Generate Parentheses

## 描述

给定n对括号，写一个函数来生成可以合法匹配的所有括号组合。

例如，给定n = 3，解集是：

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

## 解析


- 时间复杂度：O(2^n)  
- 空间复杂度：O(2^n)
- 语言：C++

```C++
class Solution 
{
public:
    void generate(vector<string> &strList, string str, int k, int length)
    {
        if(str.size() == length)
        {
            if(k==0) strList.push_back(str);
            return;
        }
        if(k>0)
        {
            generate(strList, str+')', k-1, length);
        }
        generate(strList, str+'(', k+1, length);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> strList;
        string str;
        generate(strList, str, 0, n*2);
        return strList;
    }
};
```

