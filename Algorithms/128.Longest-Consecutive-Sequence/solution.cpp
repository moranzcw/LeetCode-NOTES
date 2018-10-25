class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        map<int, int> hmap;
        hmap.clear();
        int n = num.size();
        for(int i=0; i<n; i++)
        {
            hmap.insert(pair<int, int>(num[i], i));
        }
        int ans=0, cnt=0;
        map<int, int>::iterator it;
        for(int i=0; i<num.size(); i++)
        {
            int cur = num[i];
            it = hmap.find(num[i]);
            cnt++;
            if(it!=hmap.end())
            {
                map<int, int>::iterator iter;
                while(1)
                {
                    iter = hmap.find(++cur);
                    if(iter==hmap.end())
                        break;
                    cnt++;    
                    hmap.erase(iter);
                }
                cur=num[i];
                while(1)
                {
                    iter = hmap.find(--cur);
                    if(iter==hmap.end())
                        break;
                    cnt++;    
                    hmap.erase(iter);
                }
                if(ans<cnt)
                    ans = cnt;           
                cnt=0;
            }
            cnt=0;
        }
        return ans;
    }
};