#include <bits/stdc++.h>
using namespace std;

int countBits(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n >>=1;
    }
    return count;
}
int main() {
    int n, l, s;
    cin >> n >> l >> s;
    vector<int> nums;
    vector<int> destroynums;
    for(int i=l;i<l+n;i++){
        nums.push_back(i);
        destroynums.push_back(i);
    }
    int xorSum = 0;
    for(int i=0;i<nums.size();i++){
        xorSum = xorSum ^ nums[i];
    }
    int xorDestroyed = s ^ xorSum;
    int destroyCount = countBits(xorDestroyed);
    cout << destroyCount << endl;
    if(destroyCount == 0){
        return 0;
    }
    
    return 0;
}
// 64 位输出请用 printf("%lld")


// 5 5 13

// 1
// 9 1

// 1 3 3

// 0