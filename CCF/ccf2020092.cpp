#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct people{
    int x;
    int y;
};

int n,k,t,xl,yd,xr,yu;

int main(void){
    scanf("%d %d %d %d %d %d %d",&n,&k,&t,&xl,&yd,&xr,&yu);
    int pass = 0;
    int stay = 0;
    for(int i=0;i<n;i++){
        vector<people> p;
        for(int j=0;j<t;j++){
            people ptemp;
            scanf("%d %d",&ptemp.x,&ptemp.y);
            p.push_back(ptemp);
        }
        int repeat = 0;
        int sign1 = 0;
        int sign2 = 0;
        for(int j=0;j<p.size();j++){
            if(p[j].x <= xr && p[j].x >= xl && p[j].y <= yu && p[j].y >= yd){
                sign1 = 1;
                repeat++;
            }
            else{
                repeat = 0;
            }
            if(repeat == k){
                sign2 = 1;
                break;
            }
        }
        if(sign1 == 1){
            pass++;
        }
        if(sign2 == 1){
            stay++;
        }
    }
    printf("%d\n%d\n",pass,stay);
    return 0;
}   