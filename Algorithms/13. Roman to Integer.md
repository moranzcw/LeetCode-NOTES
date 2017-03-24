# 13. Roman to Integer

## 描述
给定一个罗马数字，将其转换为整数。
假设输入数字在1到3999之间。

## 解析
没有什么特别优雅的解法，照着罗马数字的规则写就行。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int map[26];
        map['I'-'A'] = 1;
        map['V'-'A'] = 5;
        map['X'-'A'] = 10;
        map['L'-'A'] = 50; 
        map['C'-'A'] = 100;
        map['D'-'A'] = 500;
        map['M'-'A'] = 1000;

        int result = 0, n = s.size();
        s.push_back(s[n-1]);
        for(int i = 0; i < n; i++)
        {
            if(map[s[i]-'A'] >= map[s[i+1]-'A'])
                result += map[s[i]-'A'];
            else result -= map[s[i]-'A'];
        }
        return result;
    }
};
```

