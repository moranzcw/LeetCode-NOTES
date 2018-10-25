class Solution 
{
public:
    int findMin(vector<int> &num) 
    {
        if(num.size() == 1)
            return num[0];

        int midPos = num.size()/2;
        int left = 0;
        int right = num.size()-1;

        int minEle = num[0];
        while(left < midPos && midPos < right)
        {
            if(num[left] > num[midPos])
            {
                right = midPos;
                midPos = (left+right)/2;
            }
            else if(num[midPos] > num[right])
            {
                left = midPos;
                midPos = (left+right)/2;
            }
            else
            {
                minEle = num[left];
                break;
            }
        }

        if(num[left] < num[right])
            minEle = num[left];
        else
            minEle = num[right];

        return minEle;
    }
};