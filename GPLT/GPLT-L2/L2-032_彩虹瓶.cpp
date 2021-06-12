#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K; //彩虹瓶的颜色数量N、临时货架的容量M、需要判断的发货顺序的数量K
    cin >> N >> M >> K;
    while (K--){
        stack<int> s;     //这个stack表示临时货架
        bool flag = true; //判断工人能否愉快完工
        int cnt = 1;      //用来记录彩虹瓶当前需要填装的货号
        for (int i = 1; i <= N; i++){
            int temp;
            cin >> temp;
            if (temp != cnt) //如果不是当前需要填装的货号
            {
                s.push(temp);      //放在临时货架上
                if (s.size() > M) //只要大于临时货架容量就直接GG
                {
                    flag = false;
                }
            }
            else
            {
                cnt++; //填装下一个货号
                while (!s.empty())
                {
                    if (s.top() == cnt) //若放在货架最上方的货能装填就继续
                    {
                        s.pop();
                        cnt++;
                    }
                    else
                        break;
                }
            }
        }
        if (flag && cnt == N+1) //工人能愉快完工,且填装的货号达到了彩虹瓶颜色数量N
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}