class Solution 
{
public:
       int maximumGap(vector<int> &num) 
       {
        if(num.size() < 2)
          return 0;
        int min_value = num[0];
        int max_value = num[0];
        for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) 
        {
            min_value = min(*iter, min_value);
            max_value = max(*iter, max_value);
        }
        int range = ceil(double(max_value - min_value) / (num.size() - 1));
        vector<vector<int> >buckets(num.size());
        for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter++) 
        {
            int index = (*iter - min_value) / range;
            if(buckets[index].empty()) 
            {
                buckets[index].push_back(*iter);
                buckets[index].push_back(*iter);

            } 
            else 
            {
                if(*iter < buckets[index][0]) 
                {
                    buckets[index][0] = *iter;
                }
                if(*iter > buckets[index][1]) 
                {
                    buckets[index][1] = *iter;
                }
            }
        }
        int gap = 0;
         int pre = 0;
        for(int i = 1; i < buckets.size(); i++) 
        {
            if(buckets[i].empty())
              continue;
            gap = max(gap, buckets[i][0] - buckets[pre][1]);
            pre = i;
        }
        return gap;
    }
};