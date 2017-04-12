# 26. Remove Duplicates from Sorted Array

## 描述
给定一个已排序的数组，删除重复的元素，使每个元素只出现一次并返回新数组的长度。

不要使用额外空间来新建一个数组，您必须使用常数空间来完成此题。

例如，
给定输入数组 *nums* = `[1,1,2]`，

你的函数应该返回 length =`2`，数组*nums*的前两个元素分别必须为`1`和`2`。但无所谓之后的元素是多少。

## 解析
使用两个指针，第一个指针用于遍历数组，第二个指针移动慢一些，只有第一个指针发现新的不同元素时，第二个指针才会使用新的值覆盖当前元素，并移动指针位置。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int length = nums.size();
        for(int i=0,j=1;j<nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
            else
                length--;
        }
        return length;
    }
};
```

