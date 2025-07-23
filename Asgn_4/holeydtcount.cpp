// holeydtcount.cpp
// Grace Kim
// 2024-10-04
//
// For CS 311 Fall 2024
// Source file for holeydtcount
//
// uses recursive backtracking

#include "holeydtcount.hpp"
#include <vector>

using std::vector;

//Pre:
    //dim_x == board.size()
    //dim_y == board[0].size()
//Does not throw
bool checkSquare(const vector<vector<int> > & board,
                 int x, int y,
                 int dim_x, int dim_y)
{
    if(x >= 0 && x < dim_x && y >= 0 && y < dim_y)
        return (board[size_t(x)][size_t(y)] == 0);

    return false;
}

//Pre:
    //dim_x == board.size()
    //dim_y == board[0].size()
    //squaresLeft >= 0
//Does not throw
int holeyDTCount_recurse(vector<vector<int> > & board, 
                         int dim_x, int dim_y,
                         int squaresLeft)
{
    //base case
    if(squaresLeft==0)
        return 1;

    //counter
    int total = 0;
    //recursive case
    //check each square
    for(int x = 0; x < dim_x; ++x)
    {
        for(int y = 0; y < dim_y; ++y)
        {
            //find uncovered square
            if(board[size_t(x)][size_t(y)] == 0)
            {

                //check right
                if(checkSquare(board, x + 1, y, dim_x, dim_y))
                {
                    //cover current and right
                    board[size_t(x)][size_t(y)] = 1;
                    board[size_t(x + 1)][size_t(y)] = 1;

                    //recurse
                    total += holeyDTCount_recurse(board, dim_x, dim_y, squaresLeft-2);
                    
                    //set back to original
                    board[size_t(x)][size_t(y)] = 0;
                    board[size_t(x + 1)][size_t(y)] = 0;
                }

                //check below
                if(checkSquare(board, x, y + 1, dim_x, dim_y))
                {
                    //cover current and below
                    board[size_t(x)][size_t(y)] = 1;
                    board[size_t(x)][size_t(y + 1)] = 1;

                    //recurse
                    total += holeyDTCount_recurse(board, dim_x, dim_y, squaresLeft-2);
                    
                    //set back to og
                    board[size_t(x)][size_t(y)] = 0;
                    board[size_t(x)][size_t(y + 1)] = 0;
                }
                //placed dt and return 
                return total;
            } 
        }
    }
    //checked all squares
    return total; 
}

//Pre:
    //all parameters are >=0
    //hole1_x && hole2_x < dim_x
    //hole1_y && hole2_y < dim_y
//Does not throw
int holeyDTCount(int dim_x, int dim_y,
                 int hole1_x, int hole1_y,
                 int hole2_x, int hole2_y)
{
    vector<vector<int> > board(size_t(dim_x),vector<int> (size_t(dim_y), 0));

    board[size_t(hole1_x)][size_t(hole1_y)] = 1;
    board[size_t(hole2_x)][size_t(hole2_y)] = 1; 

    return holeyDTCount_recurse(board, dim_x, dim_y, (dim_x*dim_y)-2);
}
