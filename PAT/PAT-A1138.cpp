#include <bits/stdc++.h>
using namespace std;
int N;
int preorder[50010];
int inorder[50010];
int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&inorder[i]);
    }
    int preL = 0,preR = N-1,inL = 0,inR= N-1;
    int head;
    while(inL < inR){
        head = preorder[preL];
        int k = -1;
        for(int i=inL;i<=inR;i++){
            if(inorder[i] == head){
                k = i;
                break;
            }
        }
        if(inL == k){
            inL++;
            preL++;

        }
        else{
            preR = k - inL + preL;
            preL++;
            inR = k-1;
        }
    }
    printf("%d",inorder[inL]);
    return 0;
}