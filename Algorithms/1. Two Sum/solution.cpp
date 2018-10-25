class Solution 
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // 使用哈希表存储数组中的数值，key为数组中的数值，value为数组中数值对应下标 
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) 
        {
            int numberToFind = target - numbers[i];
    
            // 查找，若找到，则返回下标
            if (hash.find(numberToFind) != hash.end()) 
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);            
                return result;
            }
    
            //若没有找到，则将该值加入哈希表
            hash[numbers[i]] = i;
        }
        return result;
    }
};