#include<bits/stdc++.h>
using namespace std;
int N,K;

bool judge[10001];

int result[1010];
struct Tea{
    int num;
    int start;
    int end;
}tea[1010];

bool cmp(Tea a,Tea b){
    if(a.num == b.num){
        return a.start < b.start;
    }
    return a.num < b.num;
}

int main(void){
    scanf("%d %d",&N,&K);
    memset(judge,false,sizeof(judge));
    for(int i=1;i<=N;i++){
        result[i] = i;
    }
    for(int i=0;i<K;i++){
        scanf("%d %d %d",&tea[i].num,&tea[i].start,&tea[i].end);
        tea[i].end += tea[i].start;
        judge[tea[i].start] = true;
        judge[tea[i].end] = true;
    }
    for(int i=0;i<10001;i++){
        if(judge[i] == true){
            sort(tea,tea+K,cmp);
            for(int j=0;j<K;j++){
                if(tea[j].end == i){
                    for(int k=1;k<=N;k++){
                        if(result[k] == 0){
                            result[k] = tea[j].num;
                            break;
                        }
                    }
                }
            }
            for(int j=0;j<K;j++){
                if(tea[j].start == i){
                    for(int k=1;k<=N;k++){
                        if(result[k] == tea[j].num){
                            result[k] = 0;
                        }
                    }
                }
            }
        }
    }
    for(int k=1;k<=N;k++){
        printf("%d ",result[k]);
    }
    return 0;
}