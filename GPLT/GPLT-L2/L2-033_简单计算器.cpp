#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> numst;
stack<char> chst;
int main(void){
    // freopen("../test.in","r",stdin);
    scanf("%d",&N);
    int t1;
    char t2;
    for(int i=0;i<N;i++){
        scanf("%d",&t1);
        numst.push(t1);
    }
    getchar();
    for(int i=0;i<N-1;i++){
        scanf("%c",&t2);
        getchar();
        chst.push(t2);
    }
    int sum = 0;
    while(numst.size() != 1){
        int a = numst.top();
        numst.pop();
        int b = numst.top();
        numst.pop();
        char c = chst.top();
        chst.pop();
        if(c == '+'){
            numst.push(a+b);
        }
        else if(c == '-'){
            numst.push(b - a);
        }
        else if(c == '*'){
            numst.push(a * b);
        }
        else{
            if(a == 0){
                printf("ERROR: %d/0\n",b);
                return 0;
            }
            else{
                numst.push(b / a);
            }
        }
    }
    printf("%d\n",numst.top());
    return 0;
}