class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;
        int last = A[0];
        int i;
        for(i=1;i<A.size();i++){
            if(A[i]>last){
                last = A[i];
            }else{
                break;
            }
        }
        if(i-1==0 || i-1==A.size()-1)
            return false;
        for(i;i<A.size();i++){
            if(A[i]>=last)
                return false;
            last = A[i];
        }
        return true;
    }
};
