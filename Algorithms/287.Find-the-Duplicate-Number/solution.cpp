class Solution 
{
public: 
    int findDuplicate(vector<int>& nums) 
    {
        int min = 0, max = nums.size() - 1;
        while(min <= max)
        {
            // 找到中间那个数
            int mid = min + (max - min) / 2;
            int cnt = 0;
            // 计算总数组中有多少个数小于等于中间数
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] <= mid)
                {
                    cnt++;
                }
            }
            // 如果小于等于中间数的数量大于中间数，说明前半部分必有重复
            if(cnt > mid)
            {
                max = mid - 1;
            // 否则后半部分必有重复
            } 
            else 
            {
                min = mid + 1;
            }
        }
        return min;
    }
};