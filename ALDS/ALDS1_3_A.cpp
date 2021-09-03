#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

stack<int> st;

int main(void){
    int a,b;
    char s[100];
    while(scanf("%s",s) != EOF){
        if(s[0] == '+'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(s[0] == '-'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(s[0] == '*'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }
        else{
            st.push(atoi(s));
        }
    }
    cout << st.top() << endl;
    return 0;
}