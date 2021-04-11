#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    int sum;
    int actualsum;
}Node[110];
bool vis[10000010];
int N;
bool cmp(node a,node b){
    if(a.actualsum != b.actualsum){
        return a.actualsum > b.actualsum;
    }
    return a.sum < b.sum;
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    int temp;
    for(int i=0;i<N;i++){
        memset(vis,false,sizeof(vis));
        Node[i].actualsum = 0;
        cin >> Node[i].name >> Node[i].sum;
        for(int j=0;j<Node[i].sum;j++){
            scanf("%d",&temp);
            if(vis[temp] == false){
                vis[temp] = true;
                Node[i].actualsum++;
            }
        }
    }
    sort(Node,Node + N,cmp);
    for(int i=0;i<3;i++){
        if(i < N){
            cout << Node[i].name;
        }
        else{
            printf("-");
        }
        if(i == 2){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}