#include <bits/stdc++.h>
using namespace std;
int num[10][10];
int visit[10][10];
struct Node{
    int x;
    int y;
};
queue<Node> q;
int main(void){
    freopen("../test.in","r",stdin);
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&num[i][j]);
        }
    }

    fill(visit[0],visit[0] + 10 * 10,0);
    int count = 0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(visit[i][j] == 0){
                visit[i][j] = 1;
                if(num[i][j] == 1){
                    Node temp = {i,j};
                    q.push(temp);
                    while(!q.empty()){
                        Node temp2 = q.front();
                        int tx = temp2.x;
                        int ty = temp2.y;
                        Node temp3;
                        q.pop();
                        if(ty-1 >= 0 && num[tx][ty-1] == 1 && visit[tx][ty-1] == 0){
                            visit[tx][ty-1] = 1;
                            temp3 = {tx,ty-1};
                            
                            q.push(temp3);
                        }
                        if(ty+1 < a && num[tx][ty+1] == 1 && visit[tx][ty+1] == 0){
                            visit[tx][ty+1] = 1;
                            temp3 = {tx,ty+1};
                            q.push(temp3);
                        }
                        if(tx+1 < b && num[tx+1][ty] == 1 && visit[tx+1][ty] == 0){
                            visit[tx+1][ty] = 1;
                            temp3 = {tx + 1,ty};
                            q.push(temp3);
                        }
                        if(tx-1 >=0 && num[tx-1][ty] == 1 && visit[tx-1][ty] == 0){
                            visit[tx-1][ty] = 1;
                            temp3 = {tx - 1,ty};
                            q.push(temp3);
                        }
                    }
                    count++;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}