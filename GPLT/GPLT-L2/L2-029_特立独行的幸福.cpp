#include <bits/stdc++.h>
using namespace std;
bool isprime(int data){
    if(data == 0 || data == 1){
        return false;
    }
    for(int i=2;i<=sqrt(data);i++){
        if(data % i == 0){
            return false;
        }
    }
    return true;
}
int opnum(int x){
    int count = 0;
    while(x){
        count = count + (x%10)*(x%10);
        x /= 10;
    }
    return count;
}
bool vis[10100];
vector<int> vt[10100];
int main(void){
    freopen("../test.in","r",stdin);
    memset(vis,false,sizeof(vis));
    int left,right;
    scanf("%d %d",&left,&right);
    for(int i=left;i<=right;i++){
        int tempnum = i;
        set<int> st;
        int sign = 0;
        while(tempnum != 1){
            int temp2 = opnum(tempnum);
            int tempsize = st.size();
            st.insert(temp2);
            if(tempsize == st.size()){
                sign = 1;
                break;
            }
            tempnum = temp2;
        }
        if(sign == 0){
            set<int>::iterator it;
            for(it = st.begin();it != st.end();it++){
                vt[i].push_back(*it);
                vis[*it] = true;
            }
        }
        else{
            vis[i] = true;
        }
    }
    int count1 = 0;
    for(int i=left;i<=right;i++){
        if(vis[i] == false){
            count1 = 1;
            if(isprime(i)){
                printf("%d %d\n",i,2*vt[i].size());
            }
            else{
                printf("%d %d\n",i,vt[i].size());
            }
        }
    }
    if(count1 == 0){
        printf("SAD\n");
    }
    return 0;
}