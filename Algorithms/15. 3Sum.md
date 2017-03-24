# 15. 3Sum

## 描述
给定包含n个整数的数组S，S中是否存在元素a，b，c，使得a + b + c = 0？ 查找数组中所有的三元组，使它们的总和为零。

**Note:** 解集中不能包含重复的三元组
```
比如， 给顶数组 S = [-1, 0, 1, 2, -1, -4],

一个解集可以是：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

## 解析
将数组非降序排列，时间复杂度为O(n log n)。
使用一重循环遍历第一个数字，在第二重循环里，第二、第三个数字分别从剩下的序列两端向中间遍历。如果三数之和等于0，则得到一组解；如果三数之和小于0，说明需要增大，将第二个数往右移；如果三数之和大于0，说明需要减小，将第三个数往左移。所以总时间复杂度为O(n²)。

- 时间复杂度：O(n²)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;

        sort(num.begin(),num.end());

        for( int pos1 = 0;pos1<num.size();pos1++)
        {
            for(int pos2 = pos1 + 1, pos3 = num.size() - 1; pos2 < pos3;)
            {
                int sum = num[pos1] + num[pos2] + num[pos3];
                if(sum == 0)
                {
                        vector<int> tempResult;
                        tempResult.push_back(num[pos1]);
                        tempResult.push_back(num[pos2]);
                        tempResult.push_back(num[pos3]);
                        result.push_back(tempResult);

                        while( pos2+1 < pos3 && num[pos2+1] == num[pos2])
                            pos2++;
                        pos2++;
                        
                        while( pos3-1 > pos2 && num[pos3-1] == num[pos3])
                            pos3--;
                        pos3--;
                }
                else if(sum < 0)
                    pos2++;
                else
                    pos3--;
            }
            while( pos1+1 < num.size() && num[pos1+1] == num[pos1])
                pos1++;
        }
        return result;
    }
};
```

