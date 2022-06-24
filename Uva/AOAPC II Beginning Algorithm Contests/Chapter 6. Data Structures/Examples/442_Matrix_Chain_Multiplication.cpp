#include <bits/stdc++.h>
using namespace std;
struct node{
    int f;
    int b;
}numF[30];

stack<node> st;
int main(void){
    int n;
    scanf("%d",&n);
    string s;
    int t1,t2;
    for(int i=0;i<n;i++){
        cin >> s >> t1 >> t2;
        numF[s[0] - 'A'].f = t1;
        numF[s[0] - 'A'].b = t2;
    }
    while(cin >> s){
        if(s.length() == 1){
            cout << "0" << endl;
        }
        else{
            int num = 0;
            int sign = 0;
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<s.length();i++){
                if(s[i] == '('){
                    continue;
                }
                else if(s[i] == ')'){
                    node n1 = st.top();
                    st.pop();
                    node n2 = st.top();
                    st.pop();
                    if(n2.b != n1.f){
                        cout << "error" << endl;
                        sign = 1;
                        break;
                    }
                    node n3;
                    n3.f = n2.f;
                    n3.b = n1.b;
                    num += n2.f * n2.b * n1.b;
                    st.push(n3);
                }
                else{
                    st.push(numF[s[i] - 'A']);
                }
            }
            if(sign == 0){
                cout << num << endl;
            }
        }
    }
}

/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))
*/