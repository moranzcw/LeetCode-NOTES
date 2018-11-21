class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        string last = A[0];
        int len = A[0].size();
        int del = 0;
        for(int i=1;i<A.size();i++){
            for(int j=0;j<len;j++){
                if(last[j] != '#'){
                    if(A[i][j] >= last[j])
                        last[j] = A[i][j];
                    else{
                        last[j] = '#';
                        del += 1;
                    }
                }
            }
        }
        return del;
    }
};
