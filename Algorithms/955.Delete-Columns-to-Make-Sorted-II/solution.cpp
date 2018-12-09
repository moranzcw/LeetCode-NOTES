class Solution {
public:
    int lexicographic(vector<string>& A, vector<int> &col){
        for (int i=0; i<A.size()-1; i++){
            for(auto &j:col){
                if (A[i][j] < A[i+1][j])
                    break;
                if (A[i][j] > A[i+1][j])
                    return false;
            }
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& A) {
        int l = A.size();
        int w = A[0].size();
        
        vector<int> col;
        int res=0;
        for(int i=0;i<w;i++){
            col.push_back(i);
            if(!lexicographic(A,col)){
                col.pop_back();
                res += 1;
            }
        }
        return res;
    }
};

