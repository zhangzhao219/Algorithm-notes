#include <bits/stdc++.h>
using namespace std;
vector<int> a[5];
int main(void){
    int sum;
    scanf("%d",&sum);
    while(sum--){
        int temp;
        scanf("%d",&temp);
        if(temp % 5 == 0){
            if(temp % 2 == 0){
                a[0].push_back(temp);
            }
        }
        else if(temp % 5 == 1){
            a[1].push_back(temp);
        }
        else if(temp % 5 == 2){
            a[2].push_back(temp);
        }
        else if(temp  % 5 == 3){
            a[3].push_back(temp);
        }
        else{
            a[4].push_back(temp);
        }
    }
    if(a[0].size() == 0){
        printf("N ");
    }
    else{
        int a1 = 0;
        for(int i=0;i<a[0].size();i++){
            a1 += a[0][i];
        }
        printf("%d ",a1);
    }
    if(a[1].size() == 0){
        printf("N ");
    }
    else{
        int a2 = 0;
        int j = 1;
        for(int i=0;i<a[1].size();i++,j = -j){
            a2 = a2 + a[1][i] * j;
        }
        printf("%d ",a2);
    }
    if(a[2].size() == 0){
        printf("N ");
    }
    else{
        printf("%d ",a[2].size());
    }
    if(a[3].size() == 0){
        printf("N ");
    }
    else{
        double a4 = 0.0;
        for(int i=0;i<a[3].size();i++){
            a4 += double(a[3][i]);
        }
        printf("%.1f ",a4 / double(a[3].size()));
    }
    if(a[4].size() == 0){
        printf("N");
    }
    else{
        int a5 = 0;
        for(int i=0;i<a[4].size();i++){
            a5 = max(a5,a[4][i]);
        }
        printf("%d",a5);
    }
}