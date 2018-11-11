int area(int x1,int x2,int p1,int p2){
    return (x2-x1)*(p2-p1);
}

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        // 按X坐标分类，X坐标相同的分到同一个set中
        map<int, set<int> > pmap;
        for(int i=0;i<points.size();i++){
            if(pmap.find(points[i][0]) == pmap.end())
                pmap[points[i][0]] = set<int>();
            pmap[points[i][0]].insert(points[i][1]);
        }
        
        int minarea = INT_MAX;
        
        // 枚举一个X坐标，并取两个点
        for(map<int, set<int> >::iterator it1 = pmap.begin();it1 != pmap.end();it1++){
            int x1 = it1->first;
            for(set<int>::iterator p1 = (it1->second).begin();p1 != (it1->second).end();p1++){
                for(set<int>::iterator p2 = p1;p2 != (it1->second).end();p2++){
                    if(p1 == p2)
                        continue;
                    // 枚举另一个X坐标，查看是否有和上面两个点Y坐标相同的点。
                    for(map<int, set<int> >::iterator it2 = it1;it2 != pmap.end();it2++){
                        if(it1 == it2)
                            continue;
                        int x2 = it2->first;
                        if((it2->second).find(*p1) != (it2->second).end() && (it2->second).find(*p2) != (it2->second).end()){
                            int a = area(x1,x2,*p1,*p2);
                            minarea = min(a,minarea);
                        }
                    }
                }
            }
        }
        if(minarea == INT_MAX)
            return 0;
        return minarea;
    }
};
