#include <bits/stdc++.h>
using namespace std;
string a[110];
int main(void){
    freopen("../test.in","r",stdin);
    int count1 = 0;
    while(1){
        getline(cin, a[count1]);
        if(a[count1] == "."){
            break;
        }
        count1++;
    }
    printf("%d\n",count1);
    int mor = 0;
    int times = 0;
    int sign = 0;
    for(int i=0;i<count1;i++){
        if(a[i].find("chi1 huo3 guo1") != -1){
            if(sign == 0){
                sign = 1;
                mor = i + 1;
            }
            times++;
        }
    }
    if(times == 0){
        printf("-_-#\n");
        return 0;
    }
    printf("%d %d\n",mor,times);
    return 0;
}