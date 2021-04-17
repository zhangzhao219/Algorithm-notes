#include <bits/stdc++.h>
using namespace std;
int D,P;
map<string,int> mp1;
set<string> st;

struct node{
    string name;
    string id;
    int condition;
    int hh;
    int mm;
    int num;
}Node[1010];

vector<string> sickid;
vector<string> sickname;
int vectornum = 0;

bool cmp(node a,node b){
    if(a.hh != b.hh){
        return a.hh < b.hh;
    }
    else if(a.mm != b.mm){
        return a.mm < b.mm;
    }
    return a.num < b.num;
}

bool judge(string s2){
    if(s2.size() != 18){
        return false;
    }
    for(int i=0;i<18;i++){
        if(!isdigit(s2[i])){
            return false;
        }
    }
    return true;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&D,&P);
    int T,S;
    for(int i=0;i<D;i++){
        scanf("%d %d",&T,&S);
        string s1,s2,s3;
        int t1,t2,t3;
        int count1 = 0;
        for(int j=0;j<T;j++){
            cin >> s1 >> s2 >> t1;
            scanf("%d:%d",&t2,&t3);
            if(judge(s2)){
                Node[count1].name = s1;
                Node[count1].id = s2;
                Node[count1].condition = t1;
                Node[count1].hh = t2;
                Node[count1].mm = t3;
                Node[count1].num = count1;
                if(Node[count1].condition == 1){
                    int tempsize = st.size();
                    st.insert(s2);
                    if(st.size() != tempsize){
                        sickid.push_back(s2);
                        sickname.push_back(s1);
                        vectornum++;
                    }
                }
                count1++;
            }
        }
        sort(Node,Node + count1,cmp);
        int count2 = 0;
        for(int j=0;j<count1;j++){
            // cout << Node[j].name << " " << Node[j].id << endl;
            if(mp1.find(Node[j].id) == mp1.end()){
                mp1[Node[j].id] = i;
                cout << Node[j].name << " " << Node[j].id << endl;
                count2++;
            }
            else{
                if(mp1[Node[j].id] + P < i){
                    mp1[Node[j].id] = i;
                    cout << Node[j].name << " " << Node[j].id << endl;
                    count2++;
                }
            }
            if(count2 == S){
                break;
            }
        }
    }
    for(int i=0;i<vectornum;i++){
        cout << sickname[i] << " " << sickid[i] << endl;
    }
    return 0;
}