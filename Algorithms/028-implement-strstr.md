# 28. Implement strStr()

## 描述
实现strStr() 函数。

返回haystack字符串中，第一次出现needle字符串的首字符索引，如果haystack不含needle，则返回-1。

## 解析
使用两层循环，暴力比较各字符，查看haystack是否包含needle.

- 时间复杂度：O(n²)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int m = haystack.length(), n = needle.length();
        if(n == 0) return 0;
        for(int i = 0; i < m - n + 1;i++)
        {
            int j = 0;
            for(; j < n; j++)
            {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};
```

