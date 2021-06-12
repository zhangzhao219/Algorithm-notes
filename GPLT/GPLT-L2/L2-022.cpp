#include <bits/stdc++.h>
using namespace std;
struct node{
    int start;
    int data;
    int next;
}Node[100010];
int st,N;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d",&st,&N);
    int a,b,c;
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&a,&b,&c);
        Node[a].start = a;
        Node[a].data = b;
        Node[a].next = c;
    }
    vector<node> vt;
    for(int i=st;i != -1;i = Node[i].next){
        vt.push_back(Node[i]);
    }
    int vts =vt.size();
    int left = 0;
    int right = vts-1;
    while(vts > 0){
        if(vts == 1){
            printf("%05d %d -1\n",vt[right].start,vt[right].data);
            return 0;
        }
        else{
            printf("%05d %d %05d\n",vt[right].start,vt[right].data,vt[left].start);
        }
        right--;
        vts--;
        if(vts == 1){
            printf("%05d %d -1\n",vt[left].start,vt[left].data);
            return 0;
        }
        else{
            printf("%05d %d %05d\n",vt[left].start,vt[left].data,vt[right].start);
        }
        left++;
        vts--;
    }
    return 0;
}