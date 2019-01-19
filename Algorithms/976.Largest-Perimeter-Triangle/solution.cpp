bool cmp(int a, int b){
    return a > b;
}
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), cmp);
        for(int i=0;i<A.size();i++){
            for(int j=i+1;j<A.size();j++){
                if(A[j] < A[i]/2)
                    break;
                for(int k=j+1;k<A.size();k++){
                    if(A[k] + A[j] > A[i])
                        return A[i] + A[j] + A[k];
                    break;
                }
            }
        }
        return 0;
    }
};
