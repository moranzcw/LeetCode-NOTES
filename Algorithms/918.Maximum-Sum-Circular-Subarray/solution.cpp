class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size()==0)
            return 0;
        if(A.size()==1)
            return A[0];
        int ans=INT_MIN;
        int tol=0;
        int least=0;
        int num=INT_MAX;
        int sum=0;
        for(auto ele : A){
            tol+=ele;
            sum+=ele;
            if(sum<0){
                ans=max(ans,ele);
                sum=0;
            }else{
                ans=max(sum,ans);
            }
            least+=ele;
            if(least>0)
                least=0;
            else
                num=min(least,num);
        }
        if(ans<=0)
            return ans;
        else
            return max(ans,tol-num);
    }
};
