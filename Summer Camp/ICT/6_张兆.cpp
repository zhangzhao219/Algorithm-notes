#include <bits/stdc++.h>
using namespace std;
int N,M;
int num[100];
int maxvalue = 0;
vector<int> vt;
// 扫描所有的可能序列，输出最多的单词。。有点笨但是算法没问题
void DFS(int start,int fan,int nowvalue){
    // 正好做完且烦躁度为0（可以睡觉），可以退出并计算
    if(start == N && fan == 0){
        maxvalue = max(maxvalue,nowvalue);
        return;
    }
    // 烦躁度不为0，不可以
    else if(start >= N){
        return;
    }
    // 如果烦躁度小于M
    if(fan < M){
        // 继续工作
        DFS(start+1,fan+1,nowvalue + num[start]);
        // 休息
        DFS(start+1,max(0,fan-1),nowvalue);
    }
    else{
        // 如果烦躁度大于等于M不能再继续工作，必须休息到烦躁度为0
        DFS(start+fan,0,nowvalue);
    }
}
int main(void){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    DFS(0,0,0);
    printf("%d\n",maxvalue);
    return 0;
}
/*
5 2
50 30 40 20 100
*/