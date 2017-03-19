# 3. Longest Substring Without Repeating Characters


## 描述
给定一个字符串，找出不含重复字符的最长子串，返回它的长度。

例：
给定“abcabcbb”，答案是“abc”，长度为3。
给定“bbbbb”，答案是“b”，长度为1。
给定“pwwkew”，答案是“wke”，长度为3。注意答案必须是一个子串，“pwke”是一个子序列，而不是一个子串。

## 解析
使用双指针标记一个子串，并用一个数组保存子串中包含的字符，右指针向右移动以扩展字串长度，当遇到已经出现的字符，则向右移动左指针来跳过重复字符。遍历一遍字符串就能得到最大不重复字串长度。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0, right=0;
        int maxLength=0, length=0;
        vector<bool> flag(255,false);
        for(;right<s.size();right++)
        {
            if(flag[s[right]] == true)
            {
                for(;s[left] != s[right];left++)
                {
                    flag[s[left]] = false;
                    length --;
                }
                left++;
            }
            else
            {
                flag[s[right]] = true;
                length++;
                if(length > maxLength) 
                    maxLength = length;
            }
        }
        return maxLength;
    }
};
```

