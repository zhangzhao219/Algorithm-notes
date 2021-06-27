#include <bits/stdc++.h>
using namespace std;
vector<int> vt[50];
int pos[50];
int n;
int main(void){
    scanf("%d",&n);
    string s1,s2;
    int a,b;
    for(int i=0;i<n;i++){
        pos[i] = i;
        vt[i].push_back(i);
    }
    while(1){
        cin >> s1;
        if(s1 == "quit"){
            for(int i=0;i<n;i++){
                printf("%d:",i);
                for(int j=0;j<vt[i].size();j++){
                    printf(" %d",vt[i][j]);
                }
                printf("\n");
            }
            return 0;
        }
        cin >> a >> s2 >> b;
        if(a != b && pos[a] != pos[b]){
            if(s1 == "move" && s2 == "onto"){
                int aindex = pos[a];
                for(int j=vt[aindex].size()-1;vt[aindex][j] != a;j--){
                    vt[vt[aindex][j]].push_back(vt[aindex][j]);
                    pos[vt[aindex][j]] = vt[aindex][j];
                    vt[aindex].pop_back();
                }
                int bindex = pos[b];
                for(int j=vt[bindex].size()-1;vt[bindex][j] != b;j--){
                    vt[vt[bindex][j]].push_back(vt[bindex][j]);
                    pos[vt[bindex][j]] = vt[bindex][j];
                    vt[bindex].pop_back();
                }
                vt[bindex].push_back(a);
                vt[aindex].pop_back();
                pos[a] = bindex;
            }
            else if(s1 == "move" && s2 == "over"){
                int aindex = pos[a];
                for(int j=vt[aindex].size()-1;vt[aindex][j] != a;j--){
                    vt[vt[aindex][j]].push_back(vt[aindex][j]);
                    pos[vt[aindex][j]] = vt[aindex][j];
                    vt[aindex].pop_back();
                }
                int bindex = pos[b];
                vt[bindex].push_back(a);
                vt[aindex].pop_back();
                pos[a] = bindex;
            }
            else if(s1 == "pile" && s2 == "over"){
                int aindex = pos[a];
                int jb = 0;
                while(vt[aindex][jb] != a){
                    jb++;
                }
                int bindex = pos[b];
                for(int j=jb;j < vt[aindex].size();j++){
                    vt[bindex].push_back(vt[aindex][j]);
                    pos[vt[aindex][j]] = bindex;
                }
                for(int j=vt[aindex].size()-1;vt[aindex][j] != a;j--){
                    vt[aindex].pop_back();
                }
                vt[aindex].pop_back();
            }
            else{
                int aindex = pos[a];
                int jb = 0;
                while(vt[aindex][jb] != a){
                    jb++;
                }
                int bindex = pos[b];
                for(int j=vt[bindex].size()-1;vt[bindex][j] != b;j--){
                    vt[vt[bindex][j]].push_back(vt[bindex][j]);
                    pos[vt[bindex][j]] = vt[bindex][j];
                    vt[bindex].pop_back();
                }
                for(int j=jb;j < vt[aindex].size();j++){
                    vt[bindex].push_back(vt[aindex][j]);
                    pos[vt[aindex][j]] = bindex;
                }
                for(int j=vt[aindex].size()-1;vt[aindex][j] != a;j--){
                    vt[aindex].pop_back();
                }
                vt[aindex].pop_back();
            }
        }
    }
}
/*
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit
*/