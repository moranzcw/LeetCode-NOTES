#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<char> > brd;
    vector<vector<bool> > flag;
    string wrd;
    bool isExist(int row, int line, int index)
    {
        if(index == wrd.size())
            return true;
        else
        {
            if(row>=brd.size() || row<0 || line>= brd[0].size() || line<0)
                return false;
            if(flag[row][line] == true)
                return false;
            if(wrd[index] == brd[row][line])
            {
                flag[row][line] = true;
                bool temp = ( isExist(row+1,line,index+1) 
                    || isExist(row,line+1,index+1)
                    || isExist(row-1,line,index+1)
                    || isExist(row,line-1,index+1));
                flag[row][line] = false;
                return temp;
            }
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) 
    {
        brd = board;
        wrd = word;
        flag.resize(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
            {
                if(isExist(i,j,0))
                    return true;
            }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    char A[] = {'A','B','C','E'};
    char B[] = {'S','F','C','S'};
    char C[] = {'A','D','E','E'};
    vector<vector<char> > board;
    board.push_back(vector<char>(A,A+4));
    board.push_back(vector<char>(B,B+4));
    board.push_back(vector<char>(C,C+4));
    Solution sol;
    cout<<sol.exist(board,"ABCCED")<<endl;
    cout<<sol.exist(board,"SEE")<<endl;
    cout<<sol.exist(board,"ABCB")<<endl;
    return 0;
}