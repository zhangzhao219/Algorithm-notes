#include <bits/stdc++.h>
using namespace std;
struct node{
    char name[10];
    double num;
}Node[10010];
bool cmp(node a,node b){
    return a.num < b.num;
}
int N;
int main(void){
    scanf("%d",&N);
    double sum = 0.0;
    for(int i=0;i<N;i++){
        scanf("%s %lf",Node[i].name,&Node[i].num);
        sum += Node[i].num;
    }
    sum = sum / 2.0;
    sum = sum / N;
    for(int i=0;i<N;i++){
        Node[i].num = abs(Node[i].num - sum);
    }
    sort(Node,Node + N,cmp);
    printf("%.0f %s\n",sum,Node[0].name);
    return 0;
}