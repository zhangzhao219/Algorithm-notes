#include <bits/stdc++.h>
using namespace std;
char num[62] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
int n;
bool vis[62];
int main(void){
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    getchar();
    int count1 = 0;
    char t;
    for(int i=0;i<n;i++){
        scanf("%c",&t);
        for(int j=0;j<62;j++){
            if(num[j] == t){
                if(vis[j] == false){
                    vis[j] = true;
                }
                else{
                    int k = j;
                    int count2 = 0;
                    while(vis[k] == true){
                        k = (k + 1) % 62;
                        count1++;
                        count2++;
                        if(count2 > 70){
                            printf("-1\n");
                            return 0;
                        }
                    }
                    vis[k] = true;
                }
                break;
            }
        }
    }
    printf("%d\n",count1);
    return 0;
}