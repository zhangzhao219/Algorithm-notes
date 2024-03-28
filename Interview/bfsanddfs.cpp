#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> >&island, vector<vector<bool> >& visited, int x, int y, int m, int n){
    queue<pair<int, int> > q;
    visited[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        if(a-1 >= 0 && visited[a-1][b] == false && island[a-1][b] == 1){
            visited[a-1][b] = true;
            q.push({a-1,b});
        }
        if(b-1 >= 0 && visited[a][b-1] == false && island[a][b-1] == 1){
            visited[a][b-1] = true;
            q.push({a,b-1});
        }
        if(a+1 < m && visited[a+1][b] == false && island[a+1][b] == 1){
            visited[a+1][b] = true;
            q.push({a+1,b});
        }
        if(b+1 < n && visited[a][b+1] == false && island[a][b+1] == 1){
            visited[a][b+1] = true;
            q.push({a,b+1});
        }
    }
    return;
}

void DFS(vector<vector<int> >&island, vector<vector<bool> >& visited, int x, int y, int m, int n){
    if(x < 0 || y < 0 || x >= m || y >= n){
        return;
    }
    if(visited[x][y] == true || island[x][y] == 0){
        return;
    }
    visited[x][y] = true;
    DFS(island, visited, x-1, y, m, n);
    DFS(island, visited, x+1, y, m, n);
    DFS(island, visited, x, y-1, m, n);
    DFS(island, visited, x, y+1, m, n);
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
                // BFS(island, visited, i, j, m, n);
                DFS(island, visited, i, j, m, n);
            }
        }
    }
    cout << result << endl;
    return 0;
}