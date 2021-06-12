#include <bits/stdc++.h>
using namespace std;
struct group{
    char name[9];
    int age;
    int salary;
}sum[100010];
bool cmp(group a,group b){
    if(a.salary != b.salary){
        return a.salary > b.salary;
    }
    else if(a.age != b.age){
        return a.age < b.age;
    }
    return strcmp(a.name,b.name) < 0;

}
int main(void){
    int people,query;
    scanf("%d %d",&people,&query);
    for(int i=0;i<people;i++){
        scanf("%s %d %d",sum[i].name,&sum[i].age,&sum[i].salary);
    }
    sort(sum,sum+people,cmp);
    for(int i=0;i<query;i++){
        printf("Case #%d:\n",i+1);
        int num,low,high;
        scanf("%d %d %d",&num,&low,&high);
        int judge = 0;
        for(int j=0;j<people&num > 0;j++){
            if(sum[j].age >= low && sum[j].age <= high){
                printf("%s %d %d\n",sum[j].name,sum[j].age,sum[j].salary);
                judge++;
                num--;
            }
        }
        if(judge == 0){
            printf("None\n");
        }
    }
    return 0;
}