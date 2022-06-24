#include<bits/stdc++.h>
using namespace std;
int n;
bool judge(char c1,char c2){
    if((c1 == 'x' || c1 == '/') && (c2 == '+' || c2 == '-')){
        return true;
    }
    else{
        return false;
    }
}
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        queue<char> q;
        stack<char> st1;
        getchar();
        for(int j=1;j<8;j++){
            char ch;
            scanf("%c",&ch);
            if(ch >= '1' && ch <= '9'){
                q.push(ch);
            }
            else{
                if(st1.empty() == true || judge(ch,st1.top())){
                    st1.push(ch);
                }
                else{
                    while(!(st1.empty() == true || judge(ch,st1.top()))){
                        q.push(st1.top());
                        st1.pop();
                    }
                    st1.push(ch);
                }
            }
        }
        while(!st1.empty()){
            q.push(st1.top());
            st1.pop();
        }
        stack<int> st2;
        while(!q.empty()){
            char ch;
            ch = q.front();
            q.pop();
            if(ch >= '1' && ch <= '9'){
                st2.push(ch - '0');
            }
            else{
                int a = st2.top();
                st2.pop();
                int b = st2.top();
                st2.pop();
                if(ch == '+'){
                    st2.push(a+b);
                }
                else if(ch == '-'){
                    st2.push(b-a);
                }
                else if(ch == 'x'){
                    st2.push(a*b);
                }
                else if(ch == '/'){
                    st2.push(b/a);
                }
            }
        }
        if(st2.top() == 24){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
*/