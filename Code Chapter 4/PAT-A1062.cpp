#include <bits/stdc++.h>
using namespace std;
struct people{
    char s[15];
    int virtue_grade;
    int talent_grade;
    int total;
    int sign;
}People[100010];
bool cmp(people a,people b){
    if(a.sign == b.sign && a.total == b.total && a.virtue_grade == b.virtue_grade){
        return strcmp(a.s,b.s) < 0;
    }
    else if(a.sign == b.sign && a.total == b.total ){
        return a.virtue_grade > b.virtue_grade;
    }
    else if(a.sign == b.sign){
        return a.total > b.total;
    }
    return a.sign < b.sign;
}
int main(void){
    int N,L,H;
    scanf("%d %d %d",&N,&L,&H);
    int num = 0;
    for(int i=0;i<N;i++){
        char temps[15];
        int t1,t2;
        scanf("%s %d %d",temps,&t1,&t2);
        if(t1 >= L && t2 >= L){
            strcpy(People[num].s,temps);
            People[num].virtue_grade = t1;
            People[num].talent_grade = t2;
            People[num].total = t1 + t2;
            if(t1 >= H && t2 >= H){
                People[num].sign = 1;
            }
            else if(t1 >= H && t2 < H){
                People[num].sign = 2;
            }
            else if(t1 <= H && t2 <= H && t1 >= t2){
                People[num].sign = 3;
            }
            else{
                People[num].sign = 4;
            }
            num++;
        }
    }
    sort(People,People + num,cmp);
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%s %d %d\n",People[i].s,People[i].virtue_grade,People[i].talent_grade);
    }
}