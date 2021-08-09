#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int N;
string in[50];
string out[50];
stack<string> st; 
// 使用栈来模拟入栈出栈的过程，并记忆最大的栈容量，通过出栈的序列决定入栈的时机，如果都入栈了还不能满足出栈的要求，则认为内存管理存在问题
int main(void){
    scanf("%d",&N);
    int totalall = 0;//存储至少需要的内存容量
    for(int i=0;i<N;i++){
        cin >> in[i];
    }
    int t;
    for(int i=0;i<N;i++){
        scanf("%d",&t);
        mp[in[i]] = t;
    }
    for(int i=0;i<N;i++){
        cin >> out[i];
    }
    int inindex = 0; // 入栈指针
    int outindex = 0; // 出栈指针
    int temptotal = 0; // 总最大的
    // 模拟入栈出栈过程
    while(1){
        while(st.empty() || out[outindex] != st.top()){
            // 越界说明有问题
            if(inindex == N){
                printf("Memory error.\n");
                return 0;
            }
            st.push(in[inindex]);
            temptotal += mp[in[inindex]];
            totalall = max(totalall,temptotal);
            inindex++;
        }
        temptotal -= mp[st.top()];
        st.pop();
        outindex++;
        // 正好完成，退出死循环
        if(outindex == N){
            break;
        }
    }
    printf("%d\n",totalall);
    return 0;
}

/*
5
a b c d e
20 40 60 20 40
c b e d a

5
a b c d e
20 40 60 20 40
c a b d e
*/
