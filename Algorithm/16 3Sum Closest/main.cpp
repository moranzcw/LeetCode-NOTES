#include <iostream>
#include <limits>  
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        size_t size = num.size();
        if (size < 3)
        {
            cout << "num size must bigger than there!" << endl;
            return 0;
        }
        sort(num.begin(), num.end());   // 对于以下的处理过程必须事先排序，类似二分搜索
        int result = 0;     // 记录最终结果
        int distance = numeric_limits<int>::max();  // signed int
        int sum = 0;        // 中间结果
        size_t i = 0, j = i + 1, k = size - 1;

        for(i = 0; i < size - 2; i++)   // 三元组的第一个元素一次遍历，范围为[0...n-3]
        {
            // 去重避免重复计算，如果和上次同则跳过
            if (i > 0 && num[i] == num[i-1])
            {
                continue;
            }
            
            j = i + 1;  // 选定三元组第一个元素后，第二个元素从第一个元素的下一个位置开始考察
            k = size - 1;   // 选定三元组第一个元素后，第三个元素从数组末尾开始考察
            while (j < k)   // 三元组的后两个元素利用左右逼近来跳过效率，选定第一个元素后，其后的所有元素只需考察一遍
            {
                sum = num[i] + num[j] + num[k];
                if (sum == target)  // 存在距离最近为0则直接返回，否则穷举选取非0最小距离
                {
                    return sum;
                }
                else if(sum < target)
                {
                    if((target - sum) < distance)
                    {
                        result = sum;
                        distance = target - sum;
                    }
                    j = j + 1;
                    // 避免重复计算，如果和上次同则跳过
                    if (num[j] == num[j-1])
                    {
                        j = j + 1;
                    }
                }
                else if(sum > target)
                {
                    if((sum - target) < distance)
                    {
                        result = sum;
                        distance = sum - target;
                    }
                    k = k - 1;
                    // 避免重复计算如果和上次同则跳过
                    if (num[k] == num[k+1])
                    {
                        k = k -1;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    // test
    int S[] = {-1,2,1,-4};
    vector<int> num(S,S+sizeof(S)/sizeof(int));
    Solution sol;
    cout << sol.threeSumClosest(num,1) <<endl;
    return 0;
}