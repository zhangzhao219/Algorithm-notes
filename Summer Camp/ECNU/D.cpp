#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    string s;
    int flag;
}Node[300];
bool isavail[200];
bool isavail2[200];
int ok[200];

int main(void){
    cin >> n;
    memset(isavail,false,sizeof(isavail));
    memset(ok,0,sizeof(ok));
    string t;
    for(int i=0;i<n;i++){
        cin >> Node[i].s >> t;
        if(t == "+"){
            Node[i].flag = 1;
        }
        else{
            Node[i].flag = 0;
            for(int j=0;j<Node[i].s.size();j++){
                isavail[Node[i].s[j]] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(Node[i].flag == 1){
            memset(isavail2,false,sizeof(isavail2));
            for(int k=0;k<Node[i].s.size();k++){
                if(isavail[Node[i].s[k]] == false){
                    isavail2[Node[i].s[k]] = true;
                }
            }
            for(int i=0;i<200;i++){
                ok[i] += isavail2[i];
            }
        }
    }
    int index = 0;
    int t2 = 0;
    for(int i=0;i<200;i++){
        if(ok[i] > t2){
            t2 = ok[i];
            index = i;
        }
    }
    printf("%d\n*%c*",ok[index],index);
    return 0;

}