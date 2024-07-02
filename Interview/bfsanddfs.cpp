#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> >& island, vector<vector<bool> >& visited, int x, int y, int m, int n){
    if(x < 0 || y < 0 || x >= m || y >= n){
        return;
    }
    if(visited[x][y] == true || island[x][y] == 0){
        return;
    }
    visited[x][y] = true;
    DFS(island, visited, x+1, y, m, n);
    DFS(island, visited, x-1, y, m, n);
    DFS(island, visited, x, y-1, m, n);
    DFS(island, visited, x, y+1, m, n);
}

void BFS(vector<vector<int> >& island, vector<vector<bool> >& visited, int x, int y, int m, int n){
    queue<pair<int, int> > q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        if(i-1 >= 0 && island[i-1][j] == 1 && visited[i-1][j] == false){
            visited[i-1][j] = true;
            q.push({i-1,j});
        }
        if(j-1 >= 0 && island[i][j-1] == 1 && visited[i][j-1] == false){
            visited[i][j-1] = true;
            q.push({i,j-1});
        }
        if(i+1 < m && island[i+1][j] == 1 && visited[i+1][j] == false){
            visited[i+1][j] = true;
            q.push({i+1,j});
        }
        if(j+1 < n && island[i][j+1] == 1 && visited[i][j+1] == false){
            visited[i][j+1] = true;
            q.push({i,j+1});
        }
    }
}

int main(){
    vector<vector<int> > island {
        {0,1,0,1,0,1},
        {0,0,0,1,0,1},
        {0,1,1,1,0,1},
        {0,1,1,1,0,1},
        {0,1,1,1,0,1},
        {0,0,0,0,0,1}
    };
    int m = island.size();
    int n = island[0].size();
    int result = 0;
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(island[i][j] == 1 && visited[i][j] == false){
                result += 1;
                BFS(island, visited, i, j, m, n);
                // DFS(island, visited, i, j, m, n);
            }
        }
    }
    cout << result << endl;
    return 0;
}