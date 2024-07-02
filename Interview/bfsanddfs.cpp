#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &island, vector<vector<bool>> &visited, int x, int y, int m, int n)
{
    visited[x][y] = true;
    vector<vector<int>> direction{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    for (int i = 0; i < direction.size(); i++)
    {
        int nowx = x + direction[i][0];
        int nowy = y + direction[i][1];
        if (nowx >= 0 && nowx < m && nowy >= 0 && nowy < n && visited[nowx][nowy] == false && island[nowx][nowy] == 1)
        {
            DFS(island, visited, nowx, nowy, m, n);
        }
    }
}

void BFS(vector<vector<int>> &island, vector<vector<bool>> &visited, int x, int y, int m, int n)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    vector<vector<int>> direction{
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
    };
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int nowx = p.first;
        int nowy = p.second;
        for (int i = 0; i < direction.size(); i++)
        {
            int afterx = nowx + direction[i][0];
            int aftery = nowy + direction[i][1];
            if (afterx >= 0 && afterx < m && aftery >= 0 && aftery < n && visited[afterx][aftery] == false && island[afterx][aftery] == 1)
            {
                visited[afterx][aftery] = true;
                q.push({afterx, aftery});
            }
        }
    }
}

int main()
{
    vector<vector<int>> island{
        {0, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1}};
    int m = island.size();
    int n = island[0].size();
    int result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (island[i][j] == 1 && visited[i][j] == false)
            {
                result += 1;
                // BFS(island, visited, i, j, m, n);
                DFS(island, visited, i, j, m, n);
            }
        }
    }
    cout << result << endl;
    return 0;
}