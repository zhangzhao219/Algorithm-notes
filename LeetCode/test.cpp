#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> q;
    for(int i=0;i<nums.size();i++){
        cout << i << "-----" << endl;
        while(!q.empty() && (nums[q.back()] <= nums[i] || i - q.front() >= k)){
            q.pop_back();
        }
        q.push_back(i);
        cout << q.front() << endl;
        if(i >= k-1){
            result.push_back(nums[q.front()]);
        }
    }
    return result;
}

int main(){
    vector<int> a = {1,3,1,2,0,5};
    maxSlidingWindow(a,3);
    // cout <<  << endl;
}