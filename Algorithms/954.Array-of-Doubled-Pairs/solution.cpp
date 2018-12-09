class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(),A.end());
        unordered_map<int,int> used;
        for(auto &i:A){
            if(used.find(i) == used.end())
                used.insert(pair<int,int>(i,1));
            else
                used[i] ++;
        }
        
        for(int i=0;i<A.size();i++){
            if((used.find(A[i]) != used.end() ) && (used[A[i]] != 0 ) ){
                used[A[i]] --;
                int d = A[i] * 2;
                if(d < 0)
                    d = A[i] / 2;
                if((used.find(d) != used.end()) && (used[d] != 0)){
                    used[d] --;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
