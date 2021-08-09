#include <bits/stdc++.h>
using namespace std;
queue<int> q;
queue<int> q2[1010];
map<int,int> mp;
int main(void){
    int index = 1;
    int n;
    while(cin >> n){
        if(n == 0){
            return 0;
        }
        printf("Scenario #%d\n",index++);
        int t;
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            int k;
            for(int j=0;j<t;j++){
                scanf("%d",&k);
                mp[k] = i;
            }
        }
        string s;
        while(cin >> s){
            if(s == "STOP"){
                break;
            }
            else if(s[0] == 'E'){
                scanf("%d",&t);
                if(q2[mp[t]].empty()){
                    q.push(mp[t]);
                }
                q2[mp[t]].push(t);
            }
            else{
                t = q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if(q2[t].empty()){
                    q.pop();
                }
            }
        }
        printf("\n");
    }
    
}