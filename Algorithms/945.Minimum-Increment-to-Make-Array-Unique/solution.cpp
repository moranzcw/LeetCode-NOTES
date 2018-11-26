class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        sort(A.begin(),A.end());
        vector<int> n;
        int last = A[0];
        int move = 0;
        for(int i=1;i<A.size();i++){
            if(A[i] == last)
                n.push_back(A[i]);
            if(A[i] - last > 1){
                int d = A[i] - last - 1;
                for(int j=0;j<d && n.size()>0;j++){
                    last = last + 1;
                    move += last  - n[n.size()-1];
                    n.erase(n.end()-1);
                }
            }
            last = A[i];
        }
        for(int i=0;i<n.size();i++){
            last = last + 1;
            move += last  - n[i];
            // cout<<last<<endl;
        }
        return move;
    }
};
