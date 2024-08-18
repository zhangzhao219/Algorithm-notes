// 5*5棋盘 左上角 0 0马 马走日
// 从左上角走到任意一个角落的期望步数
// 走过的点不能走回去
#include <bits/stdc++.h>
using namespace std;

void backtracking(int n, vector<vector<int> > &direction, vector<vector<bool> > &visited, vector<int> &result, int nowx, int nowy, int times){
    if(nowx == n-1 && nowy == n-1){
        result.push_back(times);
        return;
    }
    if(nowx < 0 || nowx >= n || nowy < 0 || nowy >= n || visited[nowx][nowy] == true){
        return;
    }
    visited[nowx][nowy] = true;
    for(int i=0;i<direction.size();i++){
        backtracking(n, direction, visited, result,nowx+direction[i][0],nowy+direction[i][1],times+1);
    }
}

int main(){
    int n = 5;
    vector<int> result;
    vector<vector<bool> > visited(n, vector<bool>(n,false));
    vector<vector<int> > direction = {
        {2, 1},{1,2},{2,-1},{1,-2},{-2,-1},{-1,-2},{-2, 1},{-1, 2}
    };
    backtracking(n, direction, visited, result,0,0,0);
    int total = 0;
    for(int i=0;i<result.size();i++){
        total += result[i];
        cout << result[i] << " ";
    }
    cout << endl;
    cout << total / result.size() << endl;
    return 0;
}

// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1