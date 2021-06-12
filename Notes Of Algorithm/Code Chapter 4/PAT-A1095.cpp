#include <bits/stdc++.h>
using namespace std;
struct car{
    char name[9];
    int h,m,s;
    int time;
    int kind;
}Car[10010],valid[10010];
bool cmp(car a,car b){
    if(strcmp(a.name,b.name) != 0){
        return strcmp(a.name,b.name) < 0;
    }
    return a.time < b.time;
}
bool cmp2(car a,car b){
    return a.time < b.time;
}
map<string,int> parktime;
int main(void){
    int N,K;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%s %d:%d:%d",Car[i].name,&Car[i].h,&Car[i].m,&Car[i].s);
        Car[i].time = Car[i].s + Car[i].m*60 + Car[i].h * 3600;
        char temps[5];
        scanf("%s",temps);
        if(strcmp(temps,"in") == 0){
            Car[i].kind = 0;
        }
        else{
            Car[i].kind = 1;
        }
    }
    sort(Car,Car + N,cmp);
    int maxtime = -1;
    int num = 0;
    for(int i=0;i<N-1;i++){
        if(strcmp(Car[i].name,Car[i+1].name) == 0 && Car[i].kind == 0 && Car[i+1].kind == 1){
            valid[num++] = Car[i];
            valid[num++] = Car[i+1];
            int inTime = Car[i+1].time - Car[i].time;
            if(parktime.count(Car[i].name) == 0){
                parktime[Car[i].name] = 0;
            }
            parktime[Car[i].name] += inTime;
            maxtime = max(maxtime,parktime[Car[i].name]);
        }
    }
    sort(valid,valid + num,cmp2);
    int now = 0,numCar = 0;

    for(int i=0;i<K;i++){
        int temph,tempm,temps,temptime;
        scanf("%d:%d:%d",&temph,&tempm,&temps);
        temptime = temps + tempm * 60 + temph * 3600;
        while(now < num && valid[now].time <= temptime){
            if(valid[now].kind == 0){
                numCar++;
            }
            else{
                numCar--;
            }
            now++;
        }
        printf("%d\n",numCar);
    }
    map<string,int>::iterator it;
    for(it=parktime.begin();it != parktime.end();it++){
        if(it->second == maxtime){
            printf("%s ",it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n",maxtime / 3600,maxtime % 3600 / 60,maxtime % 60);
    return 0;
}