#include <bits/stdc++.h>
using namespace std;
int father[1010];
int findfather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a,int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}
bool cmp(int a,int b){
    return a > b;
}
int N;
int num[1010];
vector<int> vt[1010];
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    int tempsum;
    for(int i=1;i<=N;i++){
        father[i] = i;
    }
    for(int i=1;i<=N;i++){
        scanf("%d:",&tempsum);
        int t;
        while(tempsum--){
            scanf("%d",&t);
            vt[t].push_back(i);
        }
    }
    for(int i=1;i<1010;i++){
        if(vt[i].size() >= 2){
            int t = vt[i][0];
            for(int j=1;j<=vt[i].size()-1;j++){
                Union(t,vt[i][j]);
            }
        }
    }
    memset(num,0,sizeof(num));
    for(int i=1;i<=N;i++){
        num[findfather(i)]++;
    }
    sort(num + 1,num + N + 1,cmp);
    int count1 = 0;
    for(int i=1;i<=N;i++){
        if(num[i] != 0){
            count1++;
        }
        else{
            break;
        }
    }
    printf("%d\n",count1);
    for(int i=1;i<=count1;i++){
        printf("%d",num[i]);
        if(i == count1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}