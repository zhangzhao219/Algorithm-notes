#include <bits/stdc++.h>
using namespace std;
int father[10100];
bool vis[10100];
struct node{
    int people;
    int name;
    double housenum;
    double housearea;
    bool judge;
}Node[10010];
int findfather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a,int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA < faB){
        father[faB] = faA;
    }
    else if(faB < faA){
        father[faA] = faB;
    }
}
bool cmp(node a,node b){
    if(a.judge != b.judge){
        return a.judge > b.judge;
    }
    else if(a.housearea != b.housearea){
        return a.housearea > b.housearea;
    }
    return a.name < b.name;
}
int N;
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<10010;i++){
        Node[i].housearea = 0.0;
        Node[i].housenum = 0.0;
        Node[i].judge = false;
        Node[i].people = 0;
    }
    for(int i=0;i<10100;i++){
        father[i] = i;
    }
    int own,parent,childnum,child;
    while(N--){
        scanf("%d",&own);
        vis[own] = true;
        for(int i=0;i<2;i++){
            scanf("%d",&parent);
            if(parent != -1){
                vis[parent] = true;
                Union(own,parent);
            }
        }
        scanf("%d",&childnum);
        while(childnum--){
            scanf("%d",&child);
            vis[child] = true;
            Union(own,child);
        }
        scanf("%lf %lf",&Node[own].housenum,&Node[own].housearea);
    }
    for(int i=0;i<10010;i++){
        if(findfather(i) != i){
            Node[findfather(i)].housearea += Node[i].housearea;
            Node[findfather(i)].housenum += Node[i].housenum;
            Node[findfather(i)].people++;
            Node[findfather(i)].judge = true;
        }
        else if(findfather(i) == i && vis[i] != false){
            Node[findfather(i)].people++;
            Node[findfather(i)].judge = true;
        }
    }
    int num = 0;
    for(int i=0;i<10010;i++){
        if(Node[i].judge == true){
            num++;
            Node[i].name = i;
            Node[i].housearea = Node[i].housearea / double(Node[i].people);
            Node[i].housenum = Node[i].housenum / double(Node[i].people);
        }
    }
    sort(Node,Node + 10010,cmp);
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%04d %d %.3f %.3f\n",Node[i].name,Node[i].people,Node[i].housenum,Node[i].housearea);
    }
    return 0;
}