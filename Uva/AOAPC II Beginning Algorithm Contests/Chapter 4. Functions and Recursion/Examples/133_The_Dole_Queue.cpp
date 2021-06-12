#include <bits/stdc++.h>
using namespace std;
bool num[22];
int main(void){
    int n,k,m;
    while(1){
        cin >> n >> k >> m;
        if(n == 0 && k == 0 && m == 0){
            return 0;
        }
        memset(num,false,sizeof(num));
        int count1 = n;
        int aindex = n;
        int bindex = 1;
        while(count1 > 0){
            int a = k;
            int b = m;
            while(a--){
                do{
                    aindex = aindex % n + 1;
                }while(num[aindex] == true);
            }
            while(b--){
                do{
                    bindex = (bindex + n - 2) % n + 1;
                }while(num[bindex] == true);
            }
            num[aindex] = true;
            num[bindex] = true;
            if(aindex != bindex){
                printf("%3d%3d",aindex,bindex);
                count1 -= 2;
            }
            else{
                printf("%3d",aindex);
                count1 -= 1;
            }
            if(count1 != 0){
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}