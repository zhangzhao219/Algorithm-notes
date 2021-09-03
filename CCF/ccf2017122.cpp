#include<bits/stdc++.h>
using namespace std;
int n,k;
queue<int> q;
bool judge(int num){
    if(num % k == 0 || num % 10 == k){
        return true;
    }
    return false;
}
int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int count = 1;
    while(q.size() != 1){
        if(judge(count)){
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        count++;
    }
    printf("%d",q.front());
}