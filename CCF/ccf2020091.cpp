#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int num;
    int x;
    int y;
    int dis;
}a[210];
bool cmp(node a,node b){
    if(a.dis == b.dis){
        return a.num < b.num;
    }
    return a.dis < b.dis;
}
int main(void){
    int n,x,y;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        a[i].num = i+1;
        cin >> a[i].x >> a[i].y;
        a[i].dis = (a[i].x - x) * (a[i].x - x) + (a[i].y - y) * (a[i].y - y);
    }
    sort(a,a+n,cmp);
    for(int i=0;i<3;i++){
        cout << a[i].num << endl;
    }
}