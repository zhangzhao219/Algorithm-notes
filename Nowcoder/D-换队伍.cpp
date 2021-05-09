#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    bool isin;
};
vector<node> q1;
vector<node> q2;

int inqueue[300000];
bool isin2[300000];

int main(void){
    memset(isin2,false,sizeof(isin2));
    int n1,n2,q;
    scanf("%d %d %d",&n1,&n2,&q);
    int num = 1;
    for(;num<=n1;num++){
        node tn;
        tn.data = num;
        tn.isin = false;
        q1.push_back(tn);
        inqueue[num] = 1;
    }
    for(;num <= n1 + n2;num++){
        node tn;
        tn.data = num;
        tn.isin = false;
        q2.push_back(tn);
        inqueue[num] = 2;
    }
    int temp;
    for(int i=0;i<q;i++){
        scanf("%d",&temp);
        if(inqueue[temp] == 1){
            inqueue[temp] = 2;
            node tn;
            tn.data = temp;
            tn.isin = false;
            q2.push_back(tn);
        }
        else{
            inqueue[temp] = 1;
            node tn;
            tn.data = temp;
            tn.isin = false;
            q1.push_back(tn);
        }
    }
    for(int i=q1.size() - 1;i>=0;i--){
        if(inqueue[q1[i].data] == 1 && isin2[q1[i].data] == false){
            q1[i].isin = true;
            isin2[q1[i].data] = true;
        }
    }
    for(int i=q2.size() - 1;i>=0;i--){
        if(inqueue[q2[i].data] == 2 && isin2[q2[i].data] == false){
            q2[i].isin = true;
            isin2[q2[i].data] = true;
        }
    }
    for(int i=0;i<q1.size();i++){
        if(q1[i].isin == true){
            printf("%d ",q1[i].data);
        }
    }
    printf("\n");
    for(int i=0;i<q2.size();i++){
        if(q2[i].isin == true){
            printf("%d ",q2[i].data);
        }
    }
    return 0;
}