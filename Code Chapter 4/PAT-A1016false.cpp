#include <bits/stdc++.h>
using namespace std;
int bill[24];
struct people{
    char name[25];
    char time[20];
    char sign[20];
}People[1010];

bool cmp(people a,people b){
    if(strcmp(a.name,b.name) == 0){
        return strcmp(a.time,b.time) < 0;
    }
    return strcmp(a.name,b.name) < 0;
}

int main(void){
    for(int i=0;i<24;i++){
        scanf("%d",&bill[i]);
    }
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        scanf("%s %s %s",People[i].name,People[i].time,People[i].sign);
    }
    sort(People,People + sum,cmp);
    char temps[25];
    strcpy(temps,People[0].name);
    for(int i=0;i<sum-1;i++){
        if(strcmp(People[i].name,People[i+1].name) == 0 && strcmp(People[i].sign,"on-line") == 0 && strcmp(People[i+1].sign,"off-line") == 0){
            if(strcmp(People[i].name,temps) == 0){
                
            }
            else{
                printf("%s %c%c",People[i].name,People[i].time[0],People[i].time[1]);
            }
        }
    }
    // for(int i=0;i<sum;i++){
    //     printf("%s %s %s\n",People[i].name,People[i].time,People[i].sign);
    // }
    return 0;
}