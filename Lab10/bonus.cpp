#include<bits/stdc++.h>
using namespace std;


int n, m, num, max_count, c, m_color;
vector<vector<int>> visited;

void reset(int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;
}

bool is_valid(int i, int j, int color, vector<vector<int>>& grid)
{
    return ((i>=0 && j>=0 && i<m && j<n && !visited[i][j] && grid[i][j]==color) ? true : false);
}

void DFS(int i, int j, int color, vector<vector<int>>& grid)
{
    visited[i][j] = true;
    num++;
    vector<pair<int,int>> sides = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(auto itr = sides.begin(); itr != sides.end(); itr++)
    {
        if(is_valid(i + itr -> first, j + itr -> second, color, grid))
            DFS(i + itr -> first, j + itr -> second, color, grid);
    }
}

int comp(int m, int n, vector<vector<int>>& grid)
{
    reset(m, n);
    max_count = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            num = 0;
            if(!visited[i][j])
                DFS(i, j, grid[i][j], grid);
            if(max_count < num)
            {
                max_count = num;
                m_color = grid[i][j];
            }
        }
    }
    return max_count;
}

int main()
{
   
    cin >> m >> n >> c;
    visited.reserve(m);
    for(int i = 0; i < m; i++)
        visited[i].reserve(n);
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << comp(m, n, grid) << ' ' << m_color << '\n';
    return 0;
}
