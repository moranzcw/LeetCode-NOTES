#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool isValid(vector<vector<char> > &board, int a, int b) 
    {
        for (int i = 0; i < 9; ++i) 
        {
            if (i != a && board[i][b] == board[a][b])
                return false;
        }
        for (int j = 0; j < 9; ++j) 
        {
            if (j != b && board[a][j] == board[a][b])
                return false;
        }
        int x = a / 3 * 3, y = b / 3 * 3;
        for (int i = 0; i < 3; ++i) 
        {
            for (int j = 0; j < 3; ++j) 
            {
                if (x + i != a && y + j != b 
                    && board[x + i][y + j] == board[a][b])
                    return false;
            }
        }
        return true;
    }
    
    bool solveHelper(vector<vector<char> > &board) 
    {
        for (int i = 0; i < 9; ++i) 
        {
            for (int j = 0; j < 9; ++j) 
            {
                if (board[i][j] == '.') 
                {
                    for (int k = 1; k <= 9; ++k) 
                    {
                        board[i][j] = '0' + k;
                        if (isValid(board, i, j) && solveHelper(board)) 
                        {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char> > &board) 
    {
        solveHelper(board);
    }
};

int main()
{
    char A[] = {'5','3','.','.','7','.','.','.','.'};
    char B[] = {'6','.','.','1','9','5','.','.','.'};
    char C[] = {'.','9','8','.','.','.','.','6','.'};
    char D[] = {'8','.','.','.','6','.','.','.','3'};
    char E[] = {'4','.','.','8','.','6','.','.','1'};
    char F[] = {'7','.','.','.','2','.','.','.','6'};
    char G[] = {'.','6','.','.','.','.','2','8','.'};
    char H[] = {'.','.','.','4','1','9','.','.','5'};
    char I[] = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char> > board;
    board.push_back(vector<char>(A,A+9));
    board.push_back(vector<char>(B,A+9));
    board.push_back(vector<char>(C,A+9));
    board.push_back(vector<char>(D,A+9));
    board.push_back(vector<char>(E,A+9));
    board.push_back(vector<char>(F,A+9));
    board.push_back(vector<char>(G,A+9));
    board.push_back(vector<char>(H,A+9));
    board.push_back(vector<char>(I,A+9));
    Solution sol;
    sol.solveSudoku(board);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}