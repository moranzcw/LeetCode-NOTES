#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int candy(vector<int> &ratings) 
    {
        int Total = 0;    /// Total candies
        int length = 0;  /// Continuous descending length of rate
        int nPreCanCnt = 1; /// Previous child's candy count
        int beforeDenc = nPreCanCnt;
        if(ratings.begin() != ratings.end())
        {
            Total++; //Counting the first child's candy (1).
            for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
            {
                if(*i < *(i-1))
                {
                    length++;
                    if(beforeDenc <= length)
                    {
                        Total++;
                    }
                    Total += length;
                    nPreCanCnt = 1;    //This step is important, it ensures that once we leave the decending sequence, candy number start from 1
                }
                else
                {
                    int curCanCnt = 0;
                    if(*i > *(i-1))
                    { 
                        curCanCnt = (nPreCanCnt + 1);
                    }
                    else
                    {
                        curCanCnt = 1;
                    }
                    Total += curCanCnt;
                    nPreCanCnt = curCanCnt;
                    length = 0;    //reset length of decending sequence
                    beforeDenc = curCanCnt;
                }
            }
        }
        return Total;
    }
};

int main()
{
    int a[] = {1,3,4,3,2,1};
    vector<int> ratings(a,a+6);
    Solution sol;
    cout<<sol.candy(ratings)<<endl;
    return 0;
}