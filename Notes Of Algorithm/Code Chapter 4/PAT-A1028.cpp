#include <bits/stdc++.h>
using namespace std;
struct people{
    char number[7];
    char name[10];
    int grade;
}People[100010];
bool cmp1(people a,people b){
    return strcmp(a.number,b.number) < 0;
}
bool cmp2(people a,people b){
    if(strcmp(a.name,b.name) == 0){
        return strcmp(a.number,b.number) < 0;
    }
    return strcmp(a.name,b.name) < 0;
}
bool cmp3(people a,people b){
    if(a.grade == b.grade){
        return strcmp(a.number,b.number) < 0;
    }
    return a.grade < b.grade;
}
int main(void){
    int N,C;
    scanf("%d %d",&N,&C);
    for(int i=0;i<N;i++){
        scanf("%s %s %d",People[i].number,People[i].name,&People[i].grade);
    }
    if(C == 1){
        sort(People,People + N,cmp1);
    }
    else if(C == 2){
        sort(People,People + N,cmp2);
    }
    else{
        sort(People,People + N,cmp3);
    }
    for(int i=0;i<N;i++){
        printf("%s %s %d\n",People[i].number,People[i].name,People[i].grade);
    }
    return 0;
}