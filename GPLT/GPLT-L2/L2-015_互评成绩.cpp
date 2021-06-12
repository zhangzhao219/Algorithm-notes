#include <bits/stdc++.h>
using namespace std;
int N,k,M;
struct node{
    vector<int> vt;
    int sum;
}Node[10010];
bool cmp(node a,node b){
    return a.sum > b.sum;
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d",&N,&k,&M);
    int t;
    for(int i=0;i<N;i++){
        Node[i].sum = 0;
        for(int j=0;j<k;j++){
            scanf("%d",&t);
            Node[i].vt.push_back(t);
        }
        sort(Node[i].vt.begin(),Node[i].vt.end());
        for(int j=1;j<k-1;j++){
            Node[i].sum += Node[i].vt[j];
        }
    }
    sort(Node,Node + N,cmp);
    for(int i=M-1;i>=0;i--){
        printf("%.3f",Node[i].sum / double(k-2));
        if(i == 0){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}