#include <bits/stdc++.h>
using namespace std;
struct Node{
    int address;
    int data;
    int next;
    int sign1;
    int sign2;
}node[100010];
int main(void){
    freopen("../test.in","r",stdin);
    for(int i=0;i<100010;i++){
        node[i].sign1 = -1;
        node[i].sign2 = -1.0;
    }
    int start,sum;
    scanf("%d %d",&start,&sum);
    for(int i=0;i<sum;i++){
        int tempstart;
        scanf("%d",&tempstart);
        node[tempstart].address = tempstart;
        scanf("%d %d",&node[tempstart].data,&node[tempstart].next);
    }
    vector<Node> vt;
    for(int i=start;i != -1;i = node[i].next){
        vt.push_back(node[i]);
    }
    int cnt=0,l=0,r=vt.size()-1;
	while(1){
		if(cnt+1==vt.size()){
			printf("%05d %d -1",vt[r].address,vt[r].data);
	        break;
		}
		printf("%05d %d %05d\n",vt[r].address,vt[r].data,vt[l].address);
		r--,cnt++;
		if(cnt+1==vt.size()){
			printf("%05d %d -1",vt[l].address,vt[l].data);
			break;
		}
		printf("%05d %d %05d\n",vt[l].address,vt[l].data,vt[r].address);
		l++,cnt++;
	}
    return 0;
}