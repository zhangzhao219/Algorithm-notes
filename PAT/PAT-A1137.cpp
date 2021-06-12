#include <bits/stdc++.h>
using namespace std;
int P,M,N;
map<string,int> mp;
struct node{
    string name;
    int Gp;
    int Gmt;
    int Gf;
    int G;
    node(){
        Gp = -1;
        Gmt = -1;
        Gf = -1;
        G = -1;
    }
}student[30010];

bool cmp(node a,node b){
    if(a.G != b.G){
        return a.G > b.G;
    }
    return a.name < b.name;
}

int main(void){
    scanf("%d %d %d",&P,&M,&N);
    string tname;
    int tscore;
    int index = 0;
    for(int i=0;i<P;i++){
        cin >> tname >> tscore;
        if(mp.find(tname) == mp.end()){
            mp.insert(make_pair(tname,index++));
            student[index-1].name = tname;
        }
        student[mp[tname]].Gp = tscore;
    }
    for(int i=0;i<M;i++){
        cin >> tname >> tscore;
        if(mp.find(tname) == mp.end()){
            mp.insert(make_pair(tname,index++));
            student[index-1].name = tname;
        }
        student[mp[tname]].Gmt = tscore;
    }
    for(int i=0;i<N;i++){
        cin >> tname >> tscore;
        if(mp.find(tname) == mp.end()){
            mp.insert(make_pair(tname,index++));
            student[index-1].name = tname;
        }
        student[mp[tname]].Gf = tscore;
    }
    int count1 = 0;
    for(int i=0;i<index;i++){
        if(student[i].Gp >= 200 && !(student[i].Gf == -1 && student[i].Gmt == -1)){
            if(student[i].Gmt > student[i].Gf){
                student[i].G = (int)round((double)student[i].Gmt * 0.4 + (double)student[i].Gf * 0.6);
            }
            else{
                student[i].G = student[i].Gf;
            }
        }
        if(student[i].G >= 60){
            count1++;
        }
    }
    sort(student,student + index,cmp);
    for(int i=0;i<count1;i++){
        printf("%s %d %d %d %d\n",student[i].name.c_str(),student[i].Gp,student[i].Gmt,student[i].Gf,student[i].G);
        // cout << student[i].name << " " << student[i].Gp << " " << student[i].Gmt << " " << student[i].Gf << " " << student[i].G << " ";
        // if(i != count1 -1){
        //     printf("\n");
        // }
    }
    return 0;
}