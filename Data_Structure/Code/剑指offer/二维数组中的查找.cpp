#include <iostream>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    int i = 0;
    int j = matrix[0].size() - 1;
    for (; j >= 0; j--)
    {
        int cur = matrix[i][j];
        if (target == cur)
            return true;
        else if (target > cur)
            break;
    }

    i++;
    while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size())
    {
        cout << i << "\t" << j << endl;
        int cur = matrix[i][j];
        if (target == cur)
            return true;
        else if (target > cur)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    vector<vector<int>> test = {{1, 2, 3, 7, 8},
                                {5, 10, 14, 16, 19},
                                {8, 10, 18, 19, 23},
                                {9, 12, 22, 24, 29}};
    cout << findNumberIn2DArray(test, 14) << endl;
}