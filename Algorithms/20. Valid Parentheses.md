# 20. Valid Parentheses

## 描述
给定一个仅包含字符'('，')'，'{'，'}'，'['和']'的字符串，判断输入的字符串是否有效。
括号必须以正确的顺序排列，“()”和“()[]{}”都是有效的，但“(]”和“([)]”就不是有效的。

## 解析
使用栈判断括号是否匹配是一个经典的问题。
遍历字符串，遇到左括号则入栈，遇到右括号则与栈顶的括号比较，若不匹配，则整个字符串就不匹配；若匹配，则栈顶的括号出栈。遍历完成后，检查栈是否为空，非空则表示字符串不匹配。

- 时间复杂度：O(n)  
- 空间复杂度：O(n)
- 语言：C++

```C++
class Solution
{
public:
    bool isValid(string s) 
    {
        stack<char> stk;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case '(': stk.push(')');break;
                case '[': stk.push(']');break;
                case '{': stk.push('}');break;
                case ')': 
                case ']':
                case '}':
                    if(stk.empty() || stk.top() != s[i]) 
                        return false;
                    else
                        stk.pop();
                    break;
            }
        }
        if(!stk.empty())
            return false;
        return true;
    }
};
```

