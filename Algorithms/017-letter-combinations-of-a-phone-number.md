# 17. Letter Combinations of a Phone Number

## 描述
给定一个数字字符串，返回所有由电话输入的可能字母组合。
下面给出了数字到字母的映射（和电话按钮一样）。
![](image/200px-Telephone-keypad2.svg.png)
```
输入： 数字字符串 "23"
输出： ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```
Note:
虽然上述答案是按字典顺序排列的，但您的答案可以是任何顺序。

## 解析
枚举所有情况即可

举例：
初始化一个排列{""}，其中包含一个空字符串。
1. 输入2，代表"abc"，已有排列中只有字符串""，删除""，所以得到{"a","b","c"}

2. 输入3，代表"def"
   * 删除排列中的首元素"a"，并在排列之后，分别加入'ad','ae','af'，得到{"b","c","ad","ae","af"}
   * 删除排列中的首元素"b"，并在排列之后，分别加入'bd','be','bf'，得到{"c","ad","ae","af","bd","be","bf"}
   * 删除排列中的首元素"c"，并在排列之后，分别加入'cd','ce','cf'，得到{"ad","ae","af","bd","be","bf","cd","ce","cf"}

3. 以此类推，可以枚举所有组合。

- 时间复杂度：O(n \* 3^n)  
- 空间复杂度：O(n * 3^n)
- 语言：C++

```C++
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if(digits == "")
            return result;
            
        result.push_back("");
        
        vector<string> dict(10);
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        for(int i = 0; i < digits.size(); i ++)
        {
            int size = result.size();
            for(int j = 0; j < size; j ++)
            {
                string current = result[0];
                result.erase(result.begin());
                for(int k = 0; k < dict[digits[i]-'0'].size(); k ++)
                    result.push_back(current + dict[digits[i]-'0'][k]);
            }
        }
        return result;
    }
};
```

