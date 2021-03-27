#include <bits/stdc++.h>
using namespace std;
struct student{
    int id;
    int score[6];
    int trys[6];
    int passnum;
    int perfect;
    int total;
    int rank;
}Student[10010];



bool cmp(student a,student b){
    if(a.total != b.total){
        return a.total > b.total;
    }
    else if(a.perfect != b.perfect){
        return a.perfect > b.perfect;
    }
    return a.id < b.id;
}

int main(void){
    int N,K,M;
    scanf("%d %d %d",&N,&K,&M);
    int maxscore[8];
    for(int i=1;i<=K;i++){
        scanf("%d",&maxscore[i]);
    }

    for(int i=1;i<=10010;i++){
        Student[i].id = i;
        Student[i].total = 0;
        Student[i].passnum = 0;
        Student[i].perfect = 0;
        for(int j=1;j<=K;j++){
            Student[i].score[j] = -1;
            Student[i].trys[j] = -1;
        }
    }

    for(int i=1;i<=M;i++){
        int tempid,tempnum,tempscore;
        scanf("%d %d %d",&tempid,&tempnum,&tempscore);
        Student[tempid].score[tempnum] = max(tempscore,Student[tempid].score[tempnum]);
        Student[tempid].trys[tempnum] = 0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(Student[i].score[j] == -1){
                Student[i].total += 0;
            }
            else{
                Student[i].total += Student[i].score[j];
                Student[i].passnum += 1;
                
                if(Student[i].score[j] == maxscore[j]){
                    
                    Student[i].perfect += 1;
                }
            }
        }
    }
    sort(Student + 1,Student + 1 + N,cmp);

    Student[1].rank = 1;
    for(int i=2;i<=N;i++){
        if(Student[i].total == Student[i-1].total){
            Student[i].rank = Student[i-1].rank;
        }
        else{
            Student[i].rank = i;
        }
    }

    for(int i=1;i<=N;i++){
        if(Student[i].passnum != 0){
            printf("%d %05d %d ",Student[i].rank,Student[i].id,Student[i].total);
            for(int j=1;j<=K;j++){
                if(Student[i].score[j] == -1){
                    if(Student[i].trys[j] == -1){
                        printf("-");
                    }
                    else{
                        printf("0");
                    }
                }
                else{
                    printf("%d",Student[i].score[j]);
                }
                if(j != K){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
