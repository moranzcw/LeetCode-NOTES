class Solution 
{
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<int> vecTmp;
        
        m_vecRet.clear();
        sort(num.begin(), num.end());
        combination(num, 0, vecTmp, target);
        
        return m_vecRet;
    }
    
private:
    void combination(const vector<int> &num, size_t idx, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            m_vecRet.push_back(curr);
        }
        else
        {
            for (size_t i = idx; i < num.size(); ++i)
            {
                if (i != idx && num[i] == num[i - 1])
                {
                    continue;
                }
                
                if (target >= num[i])
                {   
                    curr.push_back(num[i]);
                    combination(num, i + 1, curr, target - num[i]);
                    curr.pop_back();
                }
            }
        }
    }
    
private:
    vector<vector<int> > m_vecRet;
};