// 标题
// 较大正整数

// 题目描述
// 给定正整数，调换其中两位(只能调换一次)，使结果尽可能大​
// 312->321​
// 3241->4231​
// 321->321 （原本已经是最大就不用调换）​
// 4231->4321​
// 输入：str​
// 输出：str​
// 语言不限

#include <bits/stdc++.h>
using namespace std;
int main() {
    string num = "52134";
    vector<int> mp(10,0);
    int n = num.size();
    for(int i=0;i<n;i++){
        mp[num[i]-'0'] += 1;
    }
    string tempstr = "";
    for(int i=9;i>=0;i--){
        for(int j=0;j<mp[i];j++){
            tempstr += '0' + i;
        }
    }
    cout << tempstr << endl;
    int nowp = 0;
    for(;nowp<n;nowp++){
        if(num[nowp] != tempstr[nowp]){
            break;
        } else{
            mp[num[nowp]-'0'] -= 1;
        }
    }
    cout << "nowp " << nowp << endl;
    if(nowp == n){
        cout << num << endl;
        return 0;
    }
    int back;
    for(int i=9;i>=0;i--){
        if(mp[i] > 0){
            back = i;
            break;
        }
    }
    cout << "back " << back << endl;
    int nowq;
    for(nowq=num.size();nowq>=0;nowq--){
        if(num[nowq] - '0' == back){
            break;
        }
    }
    swap(num[nowp], num[nowq]);
    cout << num << endl;
    // "52134"
    // "54321"
    return 0;
    // 4 2 3 1  4 3 2 1
    // 5 1 2 3 4  5 4 3 2 1
    // 5 2 1 3 4  5 4 1 3 2
    // 1 2 3 4  4 2 3 1
}