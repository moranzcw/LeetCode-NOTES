# 35. Search Insert Position

## 描述

给定已经排序的数组和目标值，如果从数组中找到目标值，则返回该索引。 如果没有找到，则按顺序插入该目标值的索引。

您可以假设数组中没有重复项。

这里有几个例子。  
`[1,3,5,6]`, 5 → 2  
`[1,3,5,6]`, 2 → 1  
`[1,3,5,6]`, 7 → 4  
`[1,3,5,6]`, 0 → 0


## 解析
使用二分查找逼目标值即可。

- 时间复杂度：O(log(n))  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int mid,left = 0, right = nums.size();
        while(left < right)
        {
            mid =  left+(right-left)/2;
            if(nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }
        return nums[mid]>target?mid:mid+1;
    }
};
```

