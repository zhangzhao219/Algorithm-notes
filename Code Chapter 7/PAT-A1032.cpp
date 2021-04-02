#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    int next;
    bool flag;
}node[100010];

int main(void){
    int start1,start2,sum;
    scanf("%d %d %d",&start1,&start2,&sum);
    for(int i=0;i<sum;i++){
        int t1,t2;
        char c;
        scanf("%d %c %d",&t1,&c,&t2);
        node[t1].data = c;
        node[t1].next = t2;
        node[t1].flag = false;
    }

    int head1 = start1;
    int head2 = start2;
    while(head1 != -1){
        node[head1].flag = true;
        head1 = node[head1].next;
    }
    while(head2 != -1){
        if(node[head2].flag == true){
            printf("%05d\n",head2);
            return 0;
        }
        head2 = node[head2].next;
    }
    printf("-1\n");
    return 0;

}