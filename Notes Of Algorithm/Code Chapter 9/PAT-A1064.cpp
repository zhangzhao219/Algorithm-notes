#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int left;
    int right;
}Node[1010];
int N;
vector<int> origin;

int count1 = 0;
void inorder(int root){
    if(root > N){
        return;
    }
    inorder(root*2);
    Node[root].data = origin[count1++];
    inorder(root*2+1);
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        origin.push_back(temp);
    }
    sort(origin.begin(),origin.end());
    int root = 1;
    inorder(root);
    for(int i=1;i<=N;i++){
        printf("%d",Node[i].data);
        if(i != N){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}