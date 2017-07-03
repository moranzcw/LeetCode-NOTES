# 11. Container With Most Water

## 描述
给定n个非负整数a1，a2，...，an，其中每个数字代表一个点，坐标为（i，ai）。 连接两个端点（i，ai）和（i，0），形成n条垂直线。 找出两条线，使它们与x轴一起形成一个容器，同时容器含可以装入最多的水。

注意：您不能倾斜容器，n至少为2。

## 解析
可以将所有组成容器的情况都计算一遍，这样时间复杂度是O(n²)，但这包含了许多不必要的计算。更好的办法是，使用两个指针，分别从两端出发，向中间靠拢，时间复杂度变成了O(n)。

于是问题便成了如何设计两个指针的移动策略，使得两个指针移动时必然经过最大容积的情况。

初始时，两个指针位于两端，不妨假设左边指针高度大于右边指针高度，那么，下一步操作必然是将右边指针向左移动。因为，若将左指针向右移动，则容器宽度变小，而容器有效高度不可能更高了（因为容积以较低的右指针为准），所以容器容积必然变小，没有计算的意义。

换句话说，对于较低的右指针，它与当前左指针构成的容积，比右指针与其他任一指针所构成的容器容积都大。所以，我们的遍历方式对于每一个指针，都直接计算了这个指针所能构成容器的最大容积。

简而言之，移动策略就是，将较低的指针向中间移动。

- 时间复杂度：O(n)  
- 空间复杂度：O(1)
- 语言：C++

```C++
class Solution 
{
public:
    int maxArea(vector<int> &height) 
    {
        int left = 0;
        int right = height.size() -1;

        int maxArea = 0;
        while(left < right)
        {
            int area = (right - left)*min(height[left],height[right]);
            maxArea = max(maxArea,area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
```

