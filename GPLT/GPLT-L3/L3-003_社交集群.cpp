#include <bits/stdc++.h>
using namespace std;
int father[1010];
int isRoot[1010];
int course[1010];
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
int main(void){
    freopen("../test.in","r",stdin);
    memset(course,0,sizeof(course));
    memset(isRoot,0,sizeof(isRoot));
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        father[i] = i;
    }
    for(int i=1;i<=N;i++){
        int temp;
        scanf("%d:",&temp);
        while(temp--){
            int t2;
            scanf("%d",&t2);
            if(course[t2] == 0){
                course[t2] = i;
            }
            Union(i,findfather(course[t2]));
        }
    }
    for(int i=1;i<=N;i++){
        isRoot[findfather(i)]++;
    }
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(isRoot[i] != 0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    sort(isRoot,isRoot + N + 1,cmp);
    for(int i=0;i<cnt;i++){
        printf("%d",isRoot[i]);
        if(i != cnt - 1){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}