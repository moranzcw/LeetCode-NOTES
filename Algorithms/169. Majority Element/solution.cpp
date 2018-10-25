class Solution 
{
public:
    int majorityElement(vector<int> &num) 
    {
        int n = num.size();  
        sort(num.begin(),num.end());  
        return num[n/2]; 
    }
};