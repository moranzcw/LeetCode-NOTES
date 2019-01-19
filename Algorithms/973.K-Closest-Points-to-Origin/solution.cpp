
bool cmp(const vector<int> &p1, const vector<int> &p2){
    return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), cmp);
        return vector(points.begin(), points.begin()+K);
    }
};
