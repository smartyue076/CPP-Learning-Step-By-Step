#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool backTracking(vector<vector<char>> &board, vector<vector<bool>> &mark, string word, int i, int j, int start_index)
{
    if (start_index == word.size())
        return true;
    vector<vector<int>> vec_turn = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (vector<int> turn : vec_turn)
    {
        i += turn[0];
        j += turn[1];
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && mark[i][j] == false && board[i][j] == word[start_index])
        {
            mark[i][j] = true;
            bool result = backTracking(board, mark, word, i, j, start_index + 1);
            if (result)
                return true;
            else
            {
                mark[i][j] = false;
            }
        }
        i -= turn[0];
        j -= turn[1];
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0])
            {
                mark[i][j] = true;
                bool result = backTracking(board, mark, word, i, j, 1);
                if (result)
                {
                    return true;
                }
                mark[i][j] = false;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> input = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << exist(input, "ABCCED") << endl;
}