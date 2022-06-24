#include<bits/stdc++.h>
using namespace std;
int c,l,t;
struct num{
    int number1;
    int pos;
}Ball[1010];

bool cmp1(num a,num b){
    return a.number1 < b.number1;
}

bool cmp2(num a,num b){
    return a.pos < b.pos;
}

int temp[1010];

int main(void){
    scanf("%d %d %d",&c,&l,&t);
    for(int i=0;i<c;i++){
        scanf("%d",&Ball[i].number1);
        temp[i] = Ball[i].number1 + t;
        Ball[i].pos = i;
    }
    int l2 = 2*l;
    for(int i=0;i<c;i++){
        if(temp[i] % l2 <= l){
            temp[i] = temp[i] % l2;
        }
        else{
            temp[i] = l2 - temp[i] % l2;
        }
    }
    sort(temp,temp + c);
    sort(Ball,Ball+c,cmp1);
    for(int i=0;i<c;i++){
        Ball[i].number1 = temp[i];
    }
    sort(Ball,Ball+c,cmp2);
    for(int i=0;i<c;i++){
        printf("%d ",Ball[i].number1);
    }
    return 0;
}