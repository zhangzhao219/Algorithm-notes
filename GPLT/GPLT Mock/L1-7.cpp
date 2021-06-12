#include <bits/stdc++.h>
using namespace std;
int result[10000010];
int judge(int x,int cnt,int count1){
    int base = 1;
    for(int i=0;i<count1;i++){
        base = base * 10 + 1; 
        cnt--;
    }
    int left = 0;
    int num = 0;
    do{
        result[num++] = base / x;
        left = base - base / x * x;
        base = left * 10 + 1;
        cnt--;
    }while(cnt > 0);
    if(left == 0){
        return num;
    }
    else{
        return 0;
    }
}
int main(void){
    int x;
    scanf("%d",&x);
    if(x == 1){
        printf("1 1\n");
        return 0;
    }
    int a = x;
    int count1 = 0;
    set<int> st;
    while(a != 0){
        st.insert(a % 10);
        count1++;
        a /= 10;
    }
    set<int>::iterator it = st.begin();
    if(st.size() == 1 && *it == 1){
        printf("1 %d",count1);
        return 0;
    }
    for(int i=count1;;i++){
        int res = judge(x,i,count1);
        if(res != 0){
            for(int j=0;j<res;j++){
                printf("%d",result[j]);
            }
            printf(" %d",i);
            return 0;
        }

    }
}