#include <bits/stdc++.h>
using namespace std;
string a[110];
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        cin >> a[i];
    }
    for(int i=0;i<M;i++){
        int sum = 1;
        int count1 = 0;
        for(int j=a[0].size() - 1;j >= 0;j--){
            if(a[i][j] == 'n'){
                sum += pow(2,count1);
            }
            count1++;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}