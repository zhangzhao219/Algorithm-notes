#include <bits/stdc++.h>
using namespace std;
bool judge[10];
int a[4][4];
int main(void){
    int num[25] = {0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
    memset(judge,false,sizeof(judge));
    int signx = 0;
    int signy = 0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            judge[a[i][j]] = true;
            if(a[i][j] == 0){
                signx = i;
                signy = j;
            }
        }
    }
    for(int i=1;i<=9;i++){
        if(judge[i] == false){
            a[signx][signy] = i;
            break;
        }
    }
    for(int i=0;i<3;i++){
        scanf("%d %d",&signx,&signy);
        printf("%d\n",a[signx][signy]);
    }
    int sum = 0;
    int temp;
    scanf("%d",&temp);
    if(temp <= 3){
        sum = a[temp][1] + a[temp][2] + a[temp][3];
    }
    else if(temp <= 6){
        sum = a[1][temp-3] + a[2][temp-3] + a[3][temp-3];
    }
    else if(temp == 7){
        sum = a[1][1] + a[2][2] + a[3][3];
    }
    else{
        sum = a[1][3] + a[2][2] + a[3][1];
    }
    printf("%d\n",num[sum]);
    return 0;
}