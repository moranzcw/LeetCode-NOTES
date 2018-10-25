class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0) 
          return 0;
        int low = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++)
        {
          if(prices[i] < low) 
            low = prices[i];
          else if(prices[i] - low > ans) 
            ans = prices[i] - low;
        }
        return ans;
    }
};