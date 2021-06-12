#include <bits/stdc++.h>
using namespace std;
int N;
int num[100010];
int leftmax[100010];
int rightmin[100010];
int main(void){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    leftmax[0] = 0;
    for(int i=1;i<N;i++){
        leftmax[i] = max(leftmax[i-1],num[i-1]);
    }
    rightmin[N-1] = 0x3fffffff;
    for(int i=N-2;i>=0;i--){
        rightmin[i] = min(rightmin[i+1],num[i+1]);
    }
    vector<int> vi; 
    for(int i=0;i<N;i++){
        if(num[i] > leftmax[i] && num[i] < rightmin[i]){
            vi.push_back(num[i]);
        }
    }
    printf("%d\n",vi.size());
    for(int i=0;i<vi.size();i++){
        printf("%d",vi[i]);
        if(i != vi.size() - 1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}