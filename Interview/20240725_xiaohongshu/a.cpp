#include <bits/stdc++.h>
using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串长度。




// 示例 1:

// 输入: s = "abcabcbb"输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: s = "bbbbb"输出: 1解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"输出: 3解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3

int longzichuan(string s){
	int left = 0;
	int maxlen = 1;
	unordered_map<char, bool> mp;
	// mp['b'] = false;
	for(int right = 0; right < s.size(); right++){
		// cout << left << " " << right << " " << mp['b'] << endl;
		if(mp.find(s[right]) == mp.end() || mp[s[right]] == false){
			mp[s[right]] = true;
			maxlen = max(right - left + 1, maxlen);
			// cout << left << " " << right << " " << maxlen << endl;
			continue;
		}
		while(left <= right && mp[s[right]] == true){
			mp[s[left]] = false;
			left++;
		}
		mp[s[right]] = true;
	}
	return maxlen;
}
int main() {
	string words = "pwwkew";
	cout << longzichuan(words) << endl;
}