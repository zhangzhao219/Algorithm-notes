#include <bits/stdc++.h>
using namespace std;
struct student{
    char s[14];
    int score;
    int total_rank;
    int number;
    int local_rank;
}Student[30010];
bool cmp(student a,student b){
    if(a.score == b.score){
        return strcmp(a.s,b.s) < 0;
    }
    return a.score > b.score;
}
int main(void){
    int sum;
    scanf("%d",&sum);
    int count = 0;
    for(int i=0;i<sum;i++){
        int local_num;
        scanf("%d",&local_num);
        int count2 = 0;
        for(int j=0;j<local_num;j++){
            scanf("%s %d",Student[count].s,&Student[count].score);
            Student[count].number = i+1;
            count++;
            count2++;
        }
        sort(Student + count - count2,Student + count,cmp);
        Student[count - count2].local_rank = 1;
        for(int j=count - count2 + 1;j<count;j++){
            if(Student[j].score == Student[j-1].score){
                Student[j].local_rank = Student[j-1].local_rank;
            }
            else{
                Student[j].local_rank = j + 1 - (count - count2);
            }
        }
    }
    sort(Student,Student + count,cmp);
    Student[0].total_rank = 1;
    for(int i=1;i<count;i++){
        if(Student[i].score == Student[i-1].score){
            Student[i].total_rank = Student[i-1].total_rank;
        }
        else{
            Student[i].total_rank = i + 1;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%s %d %d %d\n",Student[i].s,Student[i].total_rank,Student[i].number,Student[i].local_rank);
    }
}