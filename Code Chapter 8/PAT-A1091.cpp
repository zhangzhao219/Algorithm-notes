#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,y,z;
};
int brain[1290][129][61];
bool vis[1290][129][61];
int X[6] = {1,-1,0,0,0,0};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {0,0,0,0,1,-1};
int M,N,L,T;
bool judge(int x,int y,int z){
    if(x < 0 || x >= M){
        return false;
    }
    if(y < 0 || y >= N){
        return false;
    }
    if(z < 0 || z >= L){
        return false;
    }
    if(vis[x][y][z] == true || brain[x][y][z] == 0){
        return false;
    }
    return true;
}
queue<Node> q;
int main(void){
    // freopen("../test.in","r",stdin);
    scanf("%d %d %d %d",&M,&N,&L,&T);
    for(int k=0;k<L;k++){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                vis[i][j][k] = false;
                scanf("%d",&brain[i][j][k]);
            }
        }
    }
    int sum = 0;
    for(int k=0;k<L;k++){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(vis[i][j][k] == false && brain[i][j][k] == 1){
                    int tempnum = 0;
                    Node temp = {i,j,k};
                    q.push(temp);
                    vis[i][j][k] = true;
                    while(!q.empty()){
                        temp = q.front();
                        q.pop();
                        tempnum++;
                        for(int t=0;t<6;t++){
                            int newX = temp.x + X[t];
                            int newY = temp.y + Y[t];
                            int newZ = temp.z + Z[t];
                            if(judge(newX,newY,newZ)){
                                Node temp2 = {newX,newY,newZ};
                                q.push(temp2);
                                vis[newX][newY][newZ] = true;
                            }
                        }
                    }
                    if(tempnum >= T){
                        sum += tempnum;
                    }
                }
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}