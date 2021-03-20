#include <bits/stdc++.h>
using namespace std;

int school[100000];

int main(void){
    memset(school,0,sizeof(school));
    int sum;
    scanf("%d",&sum);
    while(sum--){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        school[t1] += t2;
    }
    int maxnumber = 0;
    int maxscore = 0;
    for(int i=0;i<100000;i++){
        if(school[i] > maxscore){
            maxscore = school[i];
            maxnumber = i;
        }
    }
    printf("%d %d",maxnumber,maxscore);
    return 0;

}