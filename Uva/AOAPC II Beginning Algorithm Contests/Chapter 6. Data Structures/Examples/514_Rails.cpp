#include <bits/stdc++.h>
using namespace std;
int num[1010];
stack<int> st;
int n;
int main(void){
    while(cin >> n && n){
        while(1){
            int t;
            cin >> t;
            if(t == 0){
                break;
            }
            else{
                num[0] = t;
                for(int i=1;i<n;i++){
                    cin >> num[i];
                }
                while(!st.empty()){
                    st.pop();
                }
                int judge = 1;
                int numj = 0;
                int ok = 1;
                while(numj + 1 < n){
                    if(judge == num[numj]){
                        judge++;
                        numj++;
                    }
                    else if(!st.empty() && st.top() == num[numj]){
                        st.pop();
                        numj++;
                    }
                    else if(judge < n){
                        st.push(judge++);
                    }
                    else{
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1){
                    cout << "Yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
*/