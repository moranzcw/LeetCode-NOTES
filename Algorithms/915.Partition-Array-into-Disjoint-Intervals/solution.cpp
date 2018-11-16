class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> max_left(A.size());
        vector<int> min_right(A.size());
        max_left[0] = A[0];
        for(int i=1;i<max_left.size();i++){
            max_left[i] = max(A[i],max_left[i-1]);
        }
        
        min_right.back() = A.back();
        for(int i=min_right.size()-2;i>=0;i--){
            min_right[i] = min(A[i],min_right[i+1]);
        }
        
        for(int i=0;i<A.size()-1;i++){
            if(max_left[i]<=min_right[i+1])
                return i+1;
        }
        return 0;
    }
};
