#include<bits/stdc++.h>
using namespace std;
struct Node{
    int address;
    int data;
    int next;
    int flag;
}node[100010];
bool cmp(Node a,Node b){
    if(a.flag == false || b.flag == false){
        return a.flag > b.flag;
    }
    else{
        return a.data < b.data;
    }
}

int main(void){
    // freopen("../test.in","r",stdin);
    int head,sum;
    scanf("%d %d",&sum,&head);

    for(int i=0;i<sum;i++){
        int t1,tdata,t2;
        scanf("%d %d %d",&t1,&tdata,&t2);
        node[t1] = {t1,tdata,t2,false};
    }
    
    int count = 0;
    int p = head;
    while(p != -1){
        node[p].flag = true;
        count++;
        p = node[p].next;
    }
    
    if(count == 0){
        printf("0 -1");
    }
    else{
        sort(node,node+100010,cmp);
        printf("%d %05d\n",count,node[0].address);
        for(int i=0;i<count;i++){
            if(i != count-1){
                printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
            }
            else{
                printf("%05d %d -1\n",node[i].address,node[i].data);
            }
        }
    }

    return 0;

}