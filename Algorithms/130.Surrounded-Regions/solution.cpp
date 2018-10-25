class Solution 
{
public:
    void process(int i,int j,vector<vector<char> >& board)
    {
        int m=board.size();
        int n=board[0].size();

        typedef pair<int,int> point;
        queue<point> Q;
        Q.push(point(i,j));
        board[i][j]='E';
        while(!Q.empty())
        {
            point tmp=Q.front();
            Q.pop();
            
            int x=tmp.first,y=tmp.second;

            //extending
            if (x!=0&&board[x-1][y]=='O')
            {
                Q.push(point(x-1,y));
                board[x-1][y]='E';   //extended;
            }
            if (x!=m-1&&board[x+1][y]=='O')
            {
                Q.push(point(x+1,y));
                board[x+1][y]='E';   //extended;
            }
            if (y!=0&&board[x][y-1]=='O')
            {
                Q.push(point(x,y-1));
                board[x][y-1]='E';   //extended;
            }
            if (y!=n-1&&board[x][y+1]=='O')
            {
                Q.push(point(x,y+1));
                board[x][y+1]='E';   //extended;
            }
        }
    }
    void solve(vector<vector<char> >& board)
    {
        int m=board.size();
        if (m==0)
            return;
        int n=board[0].size();
        int i,j;
        for(i=0;i<m;i++)
        {
            if (board[i][0]=='O')
                process(i,0,board);
            if (board[i][n-1]=='O')
                process(i,n-1,board);
        }
        for(j=0;j<n;j++)
        {
            if (board[0][j]=='O')
                process(0,j,board);
            if (board[m-1][j]=='O')
                process(m-1,j,board);
        }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if (board[i][j]=='E')
                    board[i][j]='O';
            }
    }   
};