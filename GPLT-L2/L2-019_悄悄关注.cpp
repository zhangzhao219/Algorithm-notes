#include <bits/stdc++.h>
using namespace std;
int N,M;
string alist[5010];
struct node{
    string blist;
    int num;
}Node[10010];
bool cmp(node a,node b){
    return a.blist < b.blist;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >> alist[i];
    }
    scanf("%d",&M);
    double sum;
    for(int i=0;i<M;i++){
        cin >> Node[i].blist >> Node[i].num;
        sum += Node[i].num;
    }
    sum /= double(M);
    sort(alist,alist + N);
    sort(Node,Node + M,cmp);
    int numtemp = 0;
    int aindex = 0;
    int bindex = 0;
    while(bindex < M){
        while(aindex < N && Node[bindex].blist > alist[aindex]){
            aindex++;
        }
        if(Node[bindex].blist == alist[aindex]){
            aindex++;
            bindex++;
        }
        else{
            if(Node[bindex].num > sum){
                cout << Node[bindex].blist << endl;
                numtemp++;
            }
            bindex++;
        }
    }
    if(numtemp == 0){
        printf("Bing Mei You\n");
    }
    return 0;
}