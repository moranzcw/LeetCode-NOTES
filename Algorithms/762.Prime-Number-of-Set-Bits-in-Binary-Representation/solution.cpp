class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int arr[11] = {2,3,5,7,11,13,17,19,23,29,31};
        set<int> primeSet(arr,arr+11);
        int prime = 0;
        for(int i=L;i<=R;i++){
            int temp=0;
            int num = i;
            while(num>0){
                if(num & 1)
                    temp += 1;
                num  = num >> 1;
            }
            if(primeSet.find(temp) != primeSet.end())
                prime += 1;
        }
        return prime;
    }
};
