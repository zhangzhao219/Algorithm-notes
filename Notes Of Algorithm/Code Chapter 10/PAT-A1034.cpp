#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
bool vis[maxn];
int G[maxn][maxn];
int weight[maxn];

int N,K;

map<int,string> inttostring;
map<string,int> stringtoint;
map<string,int> Gang;

int numperson = 0;
int change(string s){
    if(stringtoint.find(s) == stringtoint.end()){
        stringtoint[s] = numperson;
        inttostring[numperson] = s;
        return numperson++;
    }
    else{
        return stringtoint[s];
    }

}

void DFS(int i,int& head,int& numMember,int& totalweight2){
    numMember++;
    vis[i] = true;
    if(weight[i] > weight[head]){
        head = i;
    }
    for(int j=0;j<numperson;j++){
        if(G[i][j] > 0){
            totalweight2 += G[i][j];
            G[i][j] = G[j][i] = 0;
            if(vis[j] == false){
                DFS(j,head,numMember,totalweight2);
            }
        }
    }
}


void DFSTrave(){
    for(int i=0;i<numperson;i++){
        if(vis[i] == false){
            int head = i,numMember = 0,totalweight2 = 0;
            DFS(i,head,numMember,totalweight2);
            if(numMember > 2 && totalweight2 >K){
                Gang[inttostring[head]] = numMember;
            }
        }
    }
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&N,&K);
    memset(vis,false,sizeof(vis));
    memset(weight,0,sizeof(weight));
    fill(G[0],G[0] + maxn * maxn,0);
    string s1,s2;
    int tempweight;
    for(int i=0;i<N;i++){
        cin >> s1 >> s2 >> tempweight;
        int id1 = change(s1);
        int id2 = change(s2);
        G[id1][id2] += tempweight;
        G[id2][id1] += tempweight;
        weight[id1] += tempweight;
        weight[id2] += tempweight;
    }
    DFSTrave();
    printf("%d\n",Gang.size());
    for(map<string,int>::iterator it = Gang.begin();it != Gang.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}