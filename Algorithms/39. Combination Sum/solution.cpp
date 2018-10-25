class Solution 
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        vector<int> vecTmp;
 
        m_vecRet.clear();
        sort(candidates.begin(), candidates.end());
        combination(candidates, 0, vecTmp, target);
 
        return m_vecRet;
    }
 
private:
    void combination(const vector<int> &candidates, size_t idx, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            m_vecRet.push_back(curr);
        }
        else
        {
            for (size_t i = idx; i < candidates.size(); ++i)
            {
                if (target >= candidates[i])
                {
                    curr.push_back(candidates[i]);
                    combination(candidates, i, curr, target - candidates[i]);
                    curr.pop_back();
                }
            }
        }
    }
 
private:
    vector<vector<int> > m_vecRet;
};