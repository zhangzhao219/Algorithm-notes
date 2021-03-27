#include <bits/stdc++.h>
using namespace std;
struct student{
    int Ge;
    int Gi;
    int id;
    double grade;
    int rank;
    int pre[6];
}Student[40010];
int quote[110];
vector<int> acquo[110];
bool cmp(student a,student b){
    if(a.grade != b.grade){
        return a.grade > b.grade;
    }
    return a.Ge > b.Ge;
}
int main(void){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<M;i++){
        scanf("%d",&quote[i]);
    }
    for(int i=0;i<N;i++){
        Student[i].id = i;
        scanf("%d %d",&Student[i].Ge,&Student[i].Gi);
        Student[i].grade = (double(Student[i].Ge) + double(Student[i].Gi)) / 2.0;
        for(int j=0;j<K;j++){
            scanf("%d",&Student[i].pre[j]);
        }
    }
    sort(Student,Student + N,cmp);
    Student[0].rank = 1;
    for(int i=1;i<N;i++){
        if(Student[i].grade == Student[i-1].grade && Student[i].Ge == Student[i-1].Ge){
            Student[i].rank = Student[i-1].rank;
        }
        else{
            Student[i].rank = i+1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            int schoolnum = Student[i].pre[j];
            if(quote[schoolnum] == 0){
                break;
            }
            else{
                if(acquo[schoolnum].size() < quote[schoolnum]){
                    acquo[schoolnum].push_back(Student[i].id);
                    break;
                }
                else if(acquo[schoolnum].size() > 0 && Student[acquo[schoolnum][acquo[schoolnum].size() - 1]].rank == Student[i].rank){
                    acquo[schoolnum].push_back(Student[i].id);
                    break;
                }
            }
        }
    }
    for(int i=0;i<M;i++){
        sort(acquo[i].begin(),acquo[i].end());
    }
    for(int i=0;i<M;i++){
        if(acquo[i].size() == 0){
            printf("\n");
        }
        else{
            for(int j=0;j<acquo[i].size();j++){
                if(j == acquo[i].size() - 1){
                    printf("%d\n",acquo[i][j]);
                }
                else{
                    printf("%d ",acquo[i][j]);
                }
            }
        }
    }
    return 0;
}

/*
5 5 3
0 0 0 5 5
100 100 0 1 2
100 99 1 2 0
99 100 2 1 0
99 99 1 0 2
98 98 2 0 1
*/