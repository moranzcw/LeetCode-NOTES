# 18. 4Sum

## 描述
给定包含n个整数的数组S，S中是否存在元素a，b，c，d，使得a + b + c + d = 0？ 查找数组中所有的四元组，使它们的总和为目标值target。
Note: 解集中不能包含重复的四元组
```
比如， 给顶数组 S = [1, 0, -1, 0, -2, 2], 目标值 target = 0.

一个解集可以是:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

## 解析
将数组非降序排列，时间复杂度为O(n log n)。

使用两重循环遍历第一个和第二个数字，在第三重循环里，第三、第四个数字分别从剩下的序列两端向中间遍历。如果三数之和等于目标值target，则得到一组解；如果三数之和小于target，说明需要增大，将第二个数往右移；如果三数之和大于target，说明需要减小，将第三个数往左移。所以总时间复杂度为O(n³)。

- 时间复杂度：O(n³)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > result;
        if(nums.size() == 0)
            return result;

        sort(nums.begin(),nums.end());

        for( int pos1 = 0;pos1<nums.size();pos1++)
        {
            for(int pos2 = pos1 + 1;pos2<nums.size();pos2++)
            {
                for(int pos3 = pos2 + 1, pos4 = nums.size() - 1; pos3 < pos4;)
                {
                    int sum = nums[pos1] + nums[pos2] + nums[pos3] + nums[pos4];
                    if(sum == target)
                    {
                            vector<int> tempResult;
                            tempResult.push_back(nums[pos1]);
                            tempResult.push_back(nums[pos2]);
                            tempResult.push_back(nums[pos3]);
                            tempResult.push_back(nums[pos4]);
                            result.push_back(tempResult);
    
                            while( pos3+1 < pos4 && nums[pos3+1] == nums[pos3])
                                pos3++;
                            pos3++;
                            
                            while( pos4-1 > pos3 && nums[pos4-1] == nums[pos4])
                                pos4--;
                            pos4--;
                    }
                    else if(sum < target)
                        pos3++;
                    else
                        pos4--;
                }
                while( pos2+1 < nums.size() && nums[pos2+1] == nums[pos2])
                    pos2++;
            }
            while( pos1+1 < nums.size() && nums[pos1+1] == nums[pos1])
                    pos1++;
        }
        return result;
    }
};
```

