#include <bits/stdc++.h>
using namespace std;
int N;
int father[1010];
int result[1010];
int course[1010];

bool cmp(int a,int b){
    return a > b;
}

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

int main(void){
    freopen("../test.in","r",stdin);
    memset(result,0,sizeof(result));
    memset(course,0,sizeof(course));
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        father[i] = i;
    }
    for(int i=1;i<=N;i++){
        int tempsum;
        scanf("%d: ",&tempsum);
        for(int j=0;j<tempsum;j++){
            int temp;
            scanf("%d",&temp);
            if(course[temp] == 0){
                course[temp] = i;
            }
            Union(i,findfather(course[temp]));
        }
    }
    for(int i=1;i<=N;i++){
        result[findfather(i)]++;
    }
    sort(result + 1,result + N + 1,cmp);
    vector<int> vt;
    int count1 = 0;
    for(int i=1;i<=N;i++){
        if(result[i] != 0){
            count1++;
            vt.push_back(result[i]);
        }
    }
    printf("%d\n",count1);
    for(int i=0;i<vt.size();i++){
        printf("%d",vt[i]);
        if(i != vt.size() - 1){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}