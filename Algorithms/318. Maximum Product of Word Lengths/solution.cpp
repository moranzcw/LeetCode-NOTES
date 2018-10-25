class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int> bitmap(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                bitmap[i] |= 1<<(words[i][j]-'a');
            }
        }
        int max = 0;
        int temp;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if( (bitmap[i] & bitmap[j]) == 0)
                {
                    temp = words[i].size()*words[j].size();
                    max = temp>max?temp:max;
                }
            }
        }
        return max;
    }
};