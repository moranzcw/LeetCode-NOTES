# 14. Longest Common Prefix

## 描述
编写一个函数来查找字符串数组中最长的公共前缀。

## 解析
假设第一个字符串为公共前缀，依次与其他字符串比对，不断更新公共前缀即可。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    string longestCommonPrefix(vector<string> &strs) 
    {
        if( strs.size() == 0)
            return "";
        string prefix = strs[0];
        for(int i = 0;i<strs.size();i++)
        {
            if(prefix.size() == 0 || strs[i].size() == 0)
                return "";
            int j = 0;
            while(prefix[j] == strs[i][j])
                j++;
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};
```

