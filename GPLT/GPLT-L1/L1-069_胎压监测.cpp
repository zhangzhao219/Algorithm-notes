#include <bits/stdc++.h>
using namespace std;
struct node{
    int num;
    int pre;
}Node[4];
bool cmp(node a,node b){
    return a.pre > b.pre;
}
int main(void){
    int alarm,miuss;
    scanf("%d %d %d %d %d %d",&Node[0].pre,&Node[1].pre,&Node[2].pre,&Node[3].pre,&alarm,&miuss);
    Node[0].num = 1;
    Node[1].num = 2;
    Node[2].num = 3;
    Node[3].num = 4;
    sort(Node,Node + 4,cmp);
    if(Node[3].pre >= alarm && Node[0].pre - Node[3].pre <= miuss){
        printf("Normal\n");
        return 0;
    }
    if(Node[3].pre < alarm && Node[2].pre < alarm){
        printf("Warning: please check all the tires!");
        return 0;
    }
    if(Node[0].pre - Node[2].pre > miuss){
        printf("Warning: please check all the tires!");
        return 0;
    }
    if(Node[3].pre < alarm && Node[2].pre >= alarm){
        printf("Warning: please check #%d!\n",Node[3].num);
        return 0;
    }
    if(Node[0].pre - Node[3].pre > miuss && Node[0].pre - Node[2].pre <= miuss){
        printf("Warning: please check #%d!\n",Node[3].num);
        return 0;
    }
}