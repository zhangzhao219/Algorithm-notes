#include <bits/stdc++.h>
using namespace std;
struct student{
    int number;
    string name;
    int machine;
    string time;
    int index;
    int sign;
}Stu[210],Stu2[210];

bool cmp(student a,student b){
    if(a.number != b.number){
        return a.number < b.number;
    }
    return a.time < b.time;
}

map<int,int> mp;
map<int,int> mp2;
int N;
int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >> Stu[i].number >> Stu[i].name >> Stu[i].machine >> Stu[i].time;
        if(mp.find(Stu[i].number) == mp.end()){
            mp[Stu[i].number] = Stu[i].machine;
            Stu[i].index = i;
            Stu[i].sign = 2;
        }
        else{
            if(mp[Stu[i].number] != Stu[i].machine){
                Stu[i].sign = 1;
                mp2[Stu[i].number] = 1;
            }
            else{
                Stu[i].sign = 0;
            }
        }
    }
    int ind = 0;
    for(int i=0;i<N;i++){
        if(Stu[i].sign == 2){
            if(mp2.find(Stu[i].number) != mp2.end()){
                Stu2[ind++] = Stu[i];
            }
        }
        else if(Stu[i].sign == 1){
            Stu2[ind++] = Stu[i];
        }
    }
    sort(Stu2,Stu2 + ind,cmp);
    for(int i=0;i<ind;i++){
        cout << Stu2[i].number << " "<< Stu2[i].name <<  " "<<Stu2[i].machine <<  " "<<Stu2[i].time << endl;
    }
    return 0;
}