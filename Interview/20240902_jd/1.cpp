// 购物车商品展示问题
// 这是一个有趣的情况，购物车中有n个商品，但手机屏幕每次只能展示k个商品，你每次向下滑动一个商品，希望每次滑动使用最小的时间复杂度算出当前手机屏幕内的最贵的商品，并说出时间发咋读是多少
// 示例：
// 购物车列表：[5,8,4,2,10,8,11,12]
// 屏幕可展示商品数：3
// 结果：[8,8,10,10,11,12]

#include<bits/stdc++.h>
using namespace std;

deque<int> dq;
// 5 8 4 2 10 8 11 12
// 5 8 8
//   8 8 8
//     8 8 10
//       8 10 10

int main(){
    vector<int> cart = {5,8,4,2,10,8,11,12};
    vector<int> result;
    int n = cart.size();
    int k = 3;
    for(int i=0;i<k;i++){
        if(dq.size() == 0){
            dq.push_front(i);
        } else{
            int t = dq.back();
            if(cart[i] >= cart[t]){
                dq.push_back(i);
            } else{
                dq.push_back(t);
            }
        }
    }
    for(int i=k;i<n;i++){
        int t = dq.back();
        result.push_back(cart[t]);
        dq.pop_front();
        if(cart[i] >= cart[t]){
            dq.push_back(i);
        } else{
            dq.push_back(t);
        }
    }
    result.push_back(cart[dq.back()]);
    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}