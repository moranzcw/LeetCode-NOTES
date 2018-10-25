class Solution 
{
public:
    int transform(vector<vector<int> > &matrix, int index)
    {
        return matrix[index/matrix[0].size()][index%matrix[0].size()];
    }

    int bSearch(vector<vector<int> > &matrix, int begin, int end, int target)
    {
        if(begin <= end)
        {
            int mid = (begin+end)/2;
            int temp = transform(matrix,mid);
            if(target == temp)
                return mid;
            else if(target < temp)
                return  bSearch(matrix,begin,mid-1,target);
            else
                return  bSearch(matrix,mid+1,end,target);
        }
        else
            return -1;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) 
    {
        if (bSearch(matrix,0,matrix.size()*matrix[0].size()-1,target) >= 0)
            return true;
        else
            return false;
    }
};