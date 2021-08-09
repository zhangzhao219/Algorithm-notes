#include <bits/stdc++.h>
using namespace std;
map<string,int> mp1;
map<int,string> mp2;
struct node{
    int t1;
    int t2;
    int dis;
    int sign;
    int index;
}Node[1010];
bool cmp(node a,node b){
    if(a.dis != b.dis){
        return a.dis < b.dis;
    }
    return a.index < b.index;
}
bool cmp2(node a,node b){
    return a.index < b.index;
}
int G[2000][2000];
int father[2000];
long long father2[2000];
long long father3[2000];
bool isvist[2000];

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
    if(faA != faB){
        father[faA] = faB;
    }
}

int N;
int main(void){
    scanf("%d",&N);
    string s1,s2;
    int t;
    int index = 0;
    for(int i=0;i<N;i++){
        cin >> s1 >> s2 >> t;
        if(mp1.find(s1) == mp1.end()){
            mp1[s1] = index;
            mp2[index] = s1;
            index++;
        }
        if(mp1.find(s2) == mp1.end()){
            mp1[s2] = index;
            mp2[index] = s2;
            index++;
        }
        Node[i].t1 = mp1[s1];
        Node[i].t2 = mp1[s2];
        Node[i].dis = t;
        Node[i].sign = 0;
        Node[i].index = i;
        G[mp1[s1]][mp1[s2]] = t;
        G[mp1[s2]][mp1[s1]] = t;
    }
    sort(Node,Node + N,cmp);
    for(int i=0;i<index;i++){
        father[i] = i;
    }
    for(int i=0;i<N;i++){
        if(findfather(Node[i].t1) != findfather(Node[i].t2)){
            Union(Node[i].t1,Node[i].t2);
            Node[i].sign = 1;
        }
    }
    sort(Node,Node + N,cmp2);
    for(int i=0;i<N;i++){
        if(Node[i].sign == 1){
            cout << mp2[Node[i].t1] << " " << mp2[Node[i].t2] << " " << Node[i].dis << endl;
        }
        else{
            G[Node[i].t1][Node[i].t2] = 0;
            G[Node[i].t2][Node[i].t1] = 0;
        }
        // printf("%d %d %d %d %d\n",Node[i].t1,Node[i].t2,Node[i].dis,Node[i].index,Node[i].sign);
    }
    for(int i=0;i<index;i++){
        father2[i] = -1;
    }
    for(int i=0;i<index;i++){
        long long tempsum = 0;
        memset(isvist,false,sizeof(isvist));
        memset(father3,0,sizeof(father3));
        isvist[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int j=0;j<index;j++){
                if(isvist[j] == false && G[a][j] != 0){
                    q.push(j);
                    father3[j] = father3[a] + G[a][j];
                    isvist[j] = true;
                }
            }
        }
        for(int k=0;k<index;k++){
            tempsum += father3[k];
        }
        father2[i] = tempsum;
    }
    long long mindis = father2[0];
    for(int i=0;i<index;i++){
        if(father2[i] < mindis){
            mindis = father2[i];
        }
    }
    for(int i=0;i<index;i++){
        if(father2[i] == mindis){
            cout << mp2[i] << " ";
        }
    }
    printf("%.2f\n",double(mindis) / double(index));
    return 0;
}