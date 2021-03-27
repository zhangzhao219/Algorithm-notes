#include <bits/stdc++.h>
using namespace std;
struct student{
    char name[15];
    char id[15];
    int grade;
}Student[110];

bool cmp(student a,student b){
    return a.grade > b.grade;
}

int main(void){
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        scanf("%s %s %d",Student[i].name,Student[i].id,&Student[i].grade);
    }
    int low,high;
    scanf("%d %d",&low,&high);
    sort(Student,Student + sum,cmp);
    int sign = 0;
    for(int i=0;i<sum;i++){
        if(Student[i].grade >= low && Student[i].grade <= high){
            sign = 1;
            printf("%s %s\n",Student[i].name,Student[i].id);
        }
    }
    if(sign == 0){
        printf("NONE");
    }
}