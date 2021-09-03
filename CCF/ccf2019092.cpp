#include<bits/stdc++.h>
using namespace std;
bool Fruit[1010];

int n;
int main(void){
    long long sum = 0;
    scanf("%d",&n);
    int temp1,temp2;
    for(int i=0;i<n;i++){
        scanf("%d",&temp1);
        int temp = 0;
        Fruit[i] = false;
        for(int j=0;j<temp1;j++){
            scanf("%d",&temp2);
            if(temp2 > 0){
                if(temp != temp2 && j != 0){
                    Fruit[i] = true;
                }
                temp = temp2;
            }
            else{
                temp += temp2;
            }
        }
        sum += temp;
    }
    int count1 = 0;
    int count2 = 0;
    for(int i=0;i<n;i++){
        if(Fruit[i] == true){
            count1++;
            if(i+2 < n){
                if(Fruit[i+1] == true && Fruit[i+2] == true){
                    count2++;
                }
            }
        }
    }
    if(Fruit[n-2] == true && Fruit[n-1] == true && Fruit[0] == true){
        count2++;
    }
    if(Fruit[n-1] == true && Fruit[0] == true && Fruit[1] == true){
        count2++;
    }
    printf("%lld %d %d\n",sum,count1,count2);
    return 0;
}
/*
4  
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/