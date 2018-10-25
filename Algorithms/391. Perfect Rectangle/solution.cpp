bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.first == p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
class Solution 
{
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) 
    {
        vector<pair<int, int> > pointsList(rectangles.size()*4,pair<int, int>(0,0));
        int acreage = 0;
        for(int i=0;i<rectangles.size();i++)
        {
            //bottom-left point
            pointsList[i*4].first = rectangles[i][0];
            pointsList[i*4].second = rectangles[i][1];
            //top-right point
            pointsList[i*4+1].first = rectangles[i][2];
            pointsList[i*4+1].second = rectangles[i][3];
            //top-left point
            pointsList[i*4+2].first = rectangles[i][0];
            pointsList[i*4+2].second = rectangles[i][3];
            //bottom-right point
            pointsList[i*4+3].first = rectangles[i][2];
            pointsList[i*4+3].second = rectangles[i][1];
            
            acreage += (rectangles[i][2]-rectangles[i][0]) * (rectangles[i][3]-rectangles[i][1]);
        
            // cout<<pointsList[i*4].first<<" "<<pointsList[i*4].second<<endl;
            // cout<<pointsList[i*4+1].first<<" "<<pointsList[i*4+1].second<<endl;
            // cout<<pointsList[i*4+2].first<<" "<<pointsList[i*4+2].second<<endl;
            // cout<<pointsList[i*4+3].first<<" "<<pointsList[i*4+3].second<<endl<<endl;
        }
        // cout<<acreage<<endl;
        sort(pointsList.begin(),pointsList.end(),cmp);
        
        vector<pair<int, int> > vertex(1,pointsList[0]);
        // cout<<pointsList[0].first<<" "<<pointsList[0].second<<endl;
        for(int i=1;i<pointsList.size();i++)
        {
            // cout<<pointsList[i].first<<" "<<pointsList[i].second<<endl;
            if(pointsList[i] == vertex.back())
                vertex.erase(vertex.end()-1);
            else
                vertex.push_back(pointsList[i]);
        }
        
        if(vertex.size()!=4)
            return false;
            
        sort(vertex.begin(),vertex.end(),cmp);
        if(acreage != (vertex[2].first-vertex[0].first)*(vertex[1].second-vertex[0].second))
            return false;
        return true;
    }
};