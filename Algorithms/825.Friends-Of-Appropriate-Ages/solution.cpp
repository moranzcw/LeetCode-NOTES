class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int count = 0;
        int edge;
        for(int i=0;i<ages.size();i++){
            int j;
            edge = ages[i] * 0.5 + 7;
            for(j=i-1;j>=0;j--)
                if(ages[j] > edge)
                    count ++;
                else
                    break;
            
            for(j=i+1;j<ages.size();j++)
                if(ages[j] == ages[i] && ages[j] > edge)
                    count ++;
                else
                    break;
        }
        
        return count;
    }
};
