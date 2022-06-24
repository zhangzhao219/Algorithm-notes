#include<bits/stdc++.h>
using namespace std;
struct fruit{
    int pos;
    int thr;
}Fruit[1010];

bool cmp(fruit a,fruit b){
    if(a.thr == b.thr){
        return a.pos < b.pos;
    }
    return a.thr < b.thr;
}

int n,m;
int main(void){
    long long sum = 0;
    long long sum1 = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        Fruit[i].thr = 0;
    }
    int temp1,temp2;
    for(int i=0;i<n;i++){
        scanf("%d",&temp1);
        sum += temp1;
        Fruit[i].pos = i+1;
        for(int j=0;j<m;j++){
            scanf("%d",&temp2);
            sum1 += temp2;
            Fruit[i].thr += temp2;
        }
    }
    sort(Fruit,Fruit + n,cmp);
    printf("%lld %d %d\n",sum + sum1,Fruit[0].pos,-Fruit[0].thr);
    return 0;
}