class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0;
        int length = A.size();
        vector<int> mod(K,0);
        for(int i = 0; i < length; i++) {
        	sum += A[i];
        	mod[((sum % K) + K) % K]++; // as the sum can be negative, taking modulo twice
        }
        
        sum = 0;
        for(int i = 0; i < K; i++) {
        	if(mod[i] > 1) {
        		sum += (mod[i] - 1) * mod[i] / 2;
        	}
        }
        sum += mod[0];
        return sum;
    }
};
