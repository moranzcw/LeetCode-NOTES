# 16. 3Sum Closest

## 描述
给定包含n个整数的数组S，在S中找到三个整数，使得它们的和最接近一个给定的目标数，target。 返回这三个整数的和。 你可以假设每个输入都有且只有一个解。

```
    比如，给定 S = {-1 2 1 -4}，和 target = 1.

    最接近 target 的和为 2。(-1 + 2 + 1 = 2).
```

## 解析
将数组非降序排列，时间复杂度为O(n log n)。

使用一重循环遍历第一个数字，在第二重循环里，第二、第三个数字分别从剩下的序列两端向中间遍历。如果三数之和等于0，则直接返回三数之和；如果三数之和小于0，说明需要增大，将第二个数往右移；如果三数之和大于0，说明需要减小，将第三个数往左移。在遍历过程中，不断更新最接近的和。总时间复杂度为O(n²)。


- 时间复杂度：O(n²)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        int closestSum = num[0]+num[1]+num[2];
        sort(num.begin(),num.end());

        for( int num1pos = 0; num1pos<num.size(); num1pos++ )
        {
            for(int num2pos=num1pos+1, num3pos=num.size()-1; num2pos < num3pos;)
            {
                int sum = num[num1pos] + num[num2pos] + num[num3pos];
                if(sum == target)
                    return target;
                
                if(abs(sum-target)<abs(closestSum-target))
                        closestSum = sum;
                
                if(sum < target)
                    num2pos++;
                else
                    num3pos--;
            }
        }
        return closestSum;
    }
};
```

