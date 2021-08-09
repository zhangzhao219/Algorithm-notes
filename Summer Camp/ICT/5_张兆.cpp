#include <bits/stdc++.h>
using namespace std;
int N;
int num[100];
int star[100];
// 初始化所有的星都为N个，左侧扫描一遍，右侧扫描一遍，扫描的过程中如果该侧的数字比数字小，则将星星的个数改为改侧的星星数-1
// 最后倒序进行输出即可
int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
        star[i] = N; // 初始化所有星都为N个
    }
    // 通过左侧的条件修改一遍
    for(int i=0;i<N-1;i++){
        if(num[i] < num[i+1]){
            star[i] = star[i+1] - 1;
        }
    }
    // 通过右侧的条件修改一遍
    for(int i=N-2;i>=0;i--){
        if(num[i+1] < num[i]){
            star[i+1] = star[i] - 1;
        }
    }
    // 统计最少需要的星
    int total = 0;
    for(int i=0;i<N;i++){
        total += N - star[i] + 1;
    }
    printf("%d\n",total);
    return 0;
}
/*
3
10 20 5

3
20 10 10

4
20 10 10 20
*/