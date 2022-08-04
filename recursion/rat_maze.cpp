#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &arr, vector<vector<int>> visited, int x, int y, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (arr[x][y] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
};
void solve(vector<string> &ans, string path, vector<vector<int>> visited, int x,
           int y, vector<vector<int>> &arr, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // down
    int newx = x + 1;
    int newy = y;
    if (isSafe(arr, visited, x, y, n))
    {
        path.push_back('D');
        solve(ans, path, visited, x, y, arr, n);
        path.pop_back();
    }
    // left
    newx = x;
    newy = y - 1;
    if (isSafe(arr, visited, x, y, n))
    {
        path.push_back('L');
        solve(ans, path, visited, x, y, arr, n);
        path.pop_back();
    }
    // right
    newx = x;
    newy = y + 1;
    if (isSafe(arr, visited, x, y, n))
    {
        path.push_back('R');
        //            path.push_back('R');
        //
        solve(ans, path, visited, x, y, arr, n);
        path.pop_back();
    }
    // up
    newx = x - 1;
    newy = y;
    if (isSafe(arr, visited, x, y, n))
    {
        path.push_back('U');
        solve(ans, path, visited, x, y, arr, n);
        path.pop_back();
    }

    visited[x][y] = 0;
};
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    // Write your code here.
    vector<string> ans;
    if (arr[0][0] == 0)
    {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = arr;
    //             vector<vector<int>>visited;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(ans, path, visited, srcx, srcy, arr, n);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = searchMaze(arr, n);
    // cout<<ans;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}