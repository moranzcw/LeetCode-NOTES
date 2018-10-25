class Solution 
{
public:
    int findPeakElement(const vector<int> &num) 
    {
        int left=0,right=num.size()-1;
        while(left<=right){
            if(left==right)
                return left;
            int mid=(left+right)/2;
            if(num[mid]<num[mid+1])
                left=mid+1;
            else
                right=mid;
        }
        return 0;
    }
};