class Solution 
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
    {
        vector<int> remainder;
        int sum =0;
        for(int i = 0; i < gas.size(); i++)
        {
            remainder.push_back(gas[i]-cost[i]);
            sum += gas[i]-cost[i];
        }
        if(sum < 0)
        {
            return -1;
        }
        else
        {
            int start;
            int cur = 0;
            do
            {
                start = cur;
                int tmp = remainder[cur++];
                while(tmp >= 0 && cur<gas.size())
                {
                    tmp += remainder[cur++];
                    if(tmp < 0)
                    {
                        break;
                    }
                }
                if(tmp >= 0 && cur == gas.size())
                {
                    return start;
                }
            }
            while(cur<gas.size());
            return -1;
        }
    }
};