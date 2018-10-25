class Solution 
{
public:
    vector<int> plusOne(vector<int> &digits) 
    {
        vector<int> answer;
        
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--) 
        {
            c += digits[i];
            answer.insert(answer.begin(), c % 10);
            c = c / 10;
        }
        if (c > 0) 
        {
            answer.insert(answer.begin(), c);
        }
        return answer;
    }
};