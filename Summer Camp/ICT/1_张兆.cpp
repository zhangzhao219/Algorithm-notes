#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    int index = 0;
    int temp = 0;
    // 直接扫描字符串
    for(int i=0;i<s.size();i++){
        // 遇到数字进行计数
        while(s[i] >= '0' && s[i] <= '9'){
            temp = temp * 10 + s[i] - '0';
            i++;
        }
        // 遇到左括号准备开始记忆字符串
        if(s[i] == '['){
            i++;
            index = i;
        }
        // 遇到右括号开始输出字符串
        if(s[i] == ']'){
            int t = i;
            for(int j=0;j<temp;j++){
                cout << s.substr(index,t - index);
            }
            temp = 0;
        }
    }
    return 0;
}

/*
2[ab]4[a]
10[a]1[c]
*/
