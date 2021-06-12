#include <bits/stdc++.h>
using namespace std;
int K;
int a[1010];
bool vis[1010];
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&K);
    while(K--){
        memset(vis,false,sizeof(vis));
        int sign = 0;
        int temp,temp2;
        scanf("%d",&temp);
        for(int i=0;i<temp;i++){
            scanf("%d",&temp2);
            if(vis[temp2] == true){
                sign = 1;
            }
            else{
                vis[temp2] = true;
            }
            a[i] = temp2;
        }
        if(sign == 0){
            for(int i=0;i<temp;i++){
                for(int j=i+1;j<temp;j++){
                    if(abs(i-j) == abs(a[i] - a[j])){
                        sign = 1;
                        break;
                    }
                }
                if(sign == 1){
                    break;
                }
            }
        }
        if(sign == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}