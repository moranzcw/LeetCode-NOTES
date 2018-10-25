// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int j=n;
        while(i<=j)
        {
            int mid=(j-i)/2+i;
            if(isBadVersion(mid))
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return i;
    }
};