#include <bits/stdc++.h>
using namespace std;
bool vis[50];
int main(void){
    freopen("./test.in","r",stdin);
    int N;
    scanf("%d",&N);
    int temp;
    int count = 0;
    memset(vis,false,sizeof(vis));
    while(N--){
        scanf("%d",&temp);
        string s = to_string(temp);
        int sum = 0;
        for(int i=0;i<s.size();i++){
            sum += s[i] - '0';
        }
        if(vis[sum] == false){
            vis[sum] = true;
            count++;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<50;i++){
        if(vis[i] == true){
            printf("%d",i);
            count--;
            if(count == 0){
                printf("\n");
                return 0;
            }
            else{
                printf(" ");
            }
        }
        
    }
    return 0;
}