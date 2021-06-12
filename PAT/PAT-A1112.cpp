#include <bits/stdc++.h>
using namespace std;
int N;
set<char> st;
set<char> st1;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    string s;
    cin >> s;
    for(int i=0;i<s.size();){
        char c = s[i];
        int count1 = 1;
        for(int j=i+1;j<s.size();j++){
            if(s[j] == c){
                count1++;
            }
            else{
                break;
            }
        }
        // printf("%d ",count1);
        if(count1 % N == 0){
            if(st1.find(c) == st1.end()){
                st.insert(c);
            }
        }
        else{
            if(st.find(c) != st.end()){
                st.erase(c);
            }
            st1.insert(c);
        }
        i += count1;
    }
    set<char>::iterator it;
    // printf("\n");
    // for(it = st.begin();it != st.end();it++){
    //     printf("%c",*it);
    // }
    // printf("\n");
    st1 = st;
    for(int i=0;i<s.size();i++){
        if(st1.find(s[i]) != st1.end()){
            printf("%c",s[i]);
            st1.erase(s[i]);
        }
    }
    printf("\n");
    for(int i=0;i<s.size();){
        printf("%c",s[i]);
        if(st.find(s[i]) != st.end()){
            i += N;
        }
        else{
            i++;
        }
    }
    printf("\n");
    // for(it = st1.begin();it != st1.end();it++){
    //     printf("%c ",*it);
    // }

    return 0;
}