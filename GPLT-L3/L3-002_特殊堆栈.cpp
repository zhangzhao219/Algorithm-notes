#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> st;
stack<int> sttemp;
vector<int> vt;

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    string t;
    int num;
    while(N--){
        cin >> t;
        if(t == "Pop"){
            if(st.empty()){
                printf("Invalid\n");
            }
            else{
                vt.erase(lower_bound(vt.begin(),vt.end(),st.top()));
                printf("%d\n",st.top());
                st.pop();
            }
        }
        else if(t == "PeekMedian"){
            if(st.empty()){
                printf("Invalid\n");
            }
            else{
                if(vt.size() % 2 == 0){
                    printf("%d\n",vt[vt.size() / 2 - 1]);
                }
                else{
                    printf("%d\n",vt[(vt.size()+1) / 2 - 1]);
                }
            }
        }
        else{
            scanf("%d",&num);
            st.push(num);
            vt.insert(lower_bound(vt.begin(),vt.end(),num),num);
        }
    }
    return 0;
}