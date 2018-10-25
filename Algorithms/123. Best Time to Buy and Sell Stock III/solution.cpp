class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int size = prices.size();
        if (size == 0)
            return 0;

        vector<int> f1(size);
        vector<int> f2(size);

        int minV = prices[0];
        for (int i = 1; i < size; i++)
        {
            minV = std::min(minV, prices[i]);
            f1[i] = std::max(f1[i-1], prices[i] - minV);
        }

        int maxV = prices[size-1];
        f2[size-1] = 0;
        for (int i = size-2; i >= 0; i--)
        {
            maxV = std::max(maxV, prices[i]);
            f2[i] = std::max(f2[i+1], maxV - prices[i]);
        }

        int sum = 0;
        for (int i = 0; i < size; i++)
            sum = std::max(sum, f1[i] + f2[i]);

        return sum;
    }
};