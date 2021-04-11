#include <bits/stdc++.h>
using namespace std;
int N,G,K;
struct node{
    string name;
    int score;
    int rank;
}Node[10010];

bool cmp(node a,node b){
    if(a.score != b.score){
        return a.score > b.score;
    }
    return a.name < b.name;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d",&N,&G,&K);
    for(int i=0;i<N;i++){
        cin >> Node[i].name >> Node[i].score;
    }
    sort(Node,Node + N,cmp);
    Node[0].rank = 1;
    for(int i=1;i<N;i++){
        if(Node[i].score == Node[i-1].score){
            Node[i].rank = Node[i-1].rank;
        }
        else{
            Node[i].rank = i + 1;
        }
    }
    int money = 0;
    for(int i=0;i<N;i++){
        if(Node[i].score >= G){
            money += 50;
        }
        else if(Node[i].score >= 60){
            money += 20;
        }
        else{
            break;
        }
    }
    printf("%d\n",money);
    for(int i=0;i<N;i++){
        if(Node[i].rank <= K){
            cout << Node[i].rank << " " << Node[i].name << " " << Node[i].score << endl;
        }
    }
    return 0;
}