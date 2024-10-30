// 【最长回文子串】
// 给你一个字符串 s，找到 s 中最长的回文子串。
// 输入：s = "babad"
// 输出："bab"

#include <bits/stdc++.h>

using namespace std;

string result = "";

void findlongest(string s){
  int minleft = 0;
  int maxright = 0;
  int longest = 1;

  int n = s.size();
  // b a b a d
  // 奇数
  int l;
  int r;
  for(int i=0;i<n;i++){
    l = i;
    r = i;
    while(l >= 0 && r < n){
      if(s[l] == s[r]){
        l -= 1;
        r += 1;
      } else{
        break;
      }
    }
    if(r - l - 1 > longest){
      minleft = l + 1;
      maxright = r - 1;
      longest = r - l - 1;
    }
  }
  // 偶数
  // b a b a d
  for(int i=0;i<n-1;i++){
    l = i;
    r = i+1;
    while(l >= 0 && r < n){
      if(s[l] == s[r]){
        sign = true;
        l -= 1;
        r += 1;
      } else{
        break;
      }
    }
    if(r - l - 1 > longest){
      minleft = l + 1;
      maxright = r - 1;
      longest = r - l - 1;
    }
  }
  result = s.substr(minleft, longest);
}

int main(){
  string s = "babad";
  findlongest(s);
  cout << result << endl;
  return 0;
}

