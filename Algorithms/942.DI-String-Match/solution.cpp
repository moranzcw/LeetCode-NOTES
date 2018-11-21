class Solution {
public:
    vector<int> diStringMatch(string S) {
        int counti = 0, countd = 0;
        for(auto c:S){
            if(c == 'I')
                counti++;
        }
        countd = S.size()-counti;
        
        vector<int> A(S.size()+1);
        int iflag = countd, dflag = countd-1;
        if(S[0] == 'I'){
            A[0] = 0;
            iflag ++;
            dflag ++;
        }else{
            A[0] = A.size()-1;
        }
        for(int i=0;i<S.size();i++){
            if(S[i] == 'I'){
                A[i+1] = iflag;
                iflag += 1;
            }else{
                A[i+1] = dflag;
                dflag -= 1;
            }
        }
        return A;
    }
};
