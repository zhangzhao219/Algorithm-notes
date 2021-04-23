#include <bits/stdc++.h>
using namespace std;
set<string> st;
int M,N,S;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d %d",&N,&M,&S);
    int count = M;
    int sign = 0;
    for(int i=1;i<=N;i++){
        string s;
        cin >> s;
        if(i >= S){
            if(count == M){
                if(st.find(s) == st.end()){
                    st.insert(s);
                    cout << s << endl;
                    sign = 1;
                    count = 1;
                }
                else{
                    continue;
                }
            }
            else{
                count++;
            }
        }
    }
    if(sign == 0){
        printf("Keep going...\n");
    }
    return 0;
}