#include <bits/stdc++.h>
using namespace std;
const int coeff[3] = {2,3,5};
int main() {
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    set<long long> s;      //用集合set来记录已经生成并取出的丑数
    pq.push(1);
    s.insert(1);

    for(int i=1; ; i++) {
        long long x = pq.top();
        pq.pop();

        if(i == 1500) {
            cout<<"The 1500'th ugly number is "<<x<<".\n";
            return 0;
        }
        for(int j=0; j<3; j++) {
            long long x2 = x * coeff[j];
            if(!s.count(x2)) {      //如果集合中没记录
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
}