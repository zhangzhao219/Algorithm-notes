#include<bits/stdc++.h>
using namespace std;

int a[100001];
int b[100001];

set<int> st;

int n;

int main(void){
    scanf("%d",&n);
    int t1,t2;
    int x = 0;
    int y = 0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&t1,&t2);
        if(t2 == 0){
            a[x++] = t1;
        }
        else{
            b[y++] = t1;
        }
        st.insert(t1);
    }
    sort(a,a+x);
    sort(b,b+y);

    int count = 0;
    int arg = 0;

    for(set<int>::iterator it1 = st.begin();it1 != st.end();it1++){
        int counttemp = 0;
        counttemp += lower_bound(a,a+x,*it1) - a;
        counttemp += b+y - lower_bound(b,b+y,*it1);
        if(counttemp >= count){
            count = counttemp;
            arg = *it1;
        }
    }
    printf("%d",arg);
    return 0;
}