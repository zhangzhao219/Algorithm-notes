#include <bits/stdc++.h>
using namespace std;
struct node{
    char s[17];
    int a;
    int b;
}Node[1010];

int main(void){
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        scanf("%s %d %d",Node[i].s,&Node[i].a,&Node[i].b);
    }
    int sum2;
    scanf("%d",&sum2);
    int t1;
    for(int i=0;i<sum2;i++){
        scanf("%d",&t1);
        for(int j=0;j<sum;j++){
            if(Node[j].a == t1){
                printf("%s %d\n",Node[j].s,Node[j].b);
                break;
            }
        }
    }
    return 0;
}