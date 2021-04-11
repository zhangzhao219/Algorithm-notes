#include <bits/stdc++.h>
using namespace std;
int father[10010];
bool people[10010];
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
    return;
}

int main(void){
    freopen("../test.in","r",stdin);
    memset(people,false,sizeof(people));
    for(int i=0;i<10010;i++){
        father[i] = i;
    }
    int N;
    scanf("%d",&N);
    int temp,father2,temp2;
    int num = 0;
    while(N--){
        scanf("%d",&temp);
        scanf("%d",&father2);
        if(people[father2] == false){
            people[father2] = true;
            num++;
        }
        for(int i=0;i<temp-1;i++){
            scanf("%d",&temp2);
            if(people[temp2] == false){
                people[temp2] = true;
                num++;
            }
            Union(father2,temp2);
        }
    }
    printf("%d ",num);
    int num2 = 0;
    memset(people,false,sizeof(people));
    for(int i=1;i<=num;i++){
        if(people[findfather(i)] == false){
            people[findfather(i)] = true;
            num2++;
        }
    }
    printf("%d\n",num2);
    int S;
    scanf("%d",&S);
    int t1,t2;
    while(S--){
        scanf("%d %d",&t1,&t2);
        if(findfather(t1) == findfather(t2)){
            printf("Y\n");
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}