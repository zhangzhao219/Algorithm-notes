#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"

// The TestCase is shown below
// Input : 1 2
// Output : 3

int findstr(string word){
	int n = word.size();
	set<char> st;
	int left = 0;
	int maxlen = 1;
	for(int right=0;right < n;right++){
		if(st.count(word[right]) == 0){
			st.insert(word[right]);
			maxlen = max(maxlen, right-left+1);
			continue;
		}
		while(left < right && st.count(word[right]) != 0){
			st.erase(word[left]);
			left += 1;
		}
		st.insert(word[right]);
	}
    return maxlen;
}
// a b c a b c b b
int main() {
	string words = "abcabcbb";
	cout << findstr(words) << endl;
  	return 0;
}