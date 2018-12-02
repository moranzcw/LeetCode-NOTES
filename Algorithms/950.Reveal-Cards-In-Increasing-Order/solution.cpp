class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=deck.size()-1;i>=0;i--){
            if(!q.empty()){
                int t = q.front();
                q.pop();
                q.push(t);
            }
            q.push(deck[i]);
        }
        vector<int> result(q.size());
        int i = q.size()-1;
        while(!q.empty()){
            result[i] = q.front();
            i--;
            q.pop();
        }
        return result;
    }
};
