class Solution 
{
public:
    string getHint(string secret, string guess) 
    {
        string result;
        int c = 0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i] == guess[i])
                c++;
        }
        result = to_string(c)+"A";
        
        vector<int> tableS(10),tableG(10);
        for(int i=0;i<secret.size();i++)
        {
            tableS[secret[i]-'0']++;
            tableG[guess[i]-'0']++;
        }
        int t = 0;
        for(int i=0;i<10;i++)
        {
            if(tableS[i] > tableG[i])
                t += tableG[i];
            else
                t += tableS[i];
        }
        result += to_string(t-c) + "B";
        return result;
    }
};