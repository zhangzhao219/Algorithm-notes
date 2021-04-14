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
        if(s2[i] < '0' || s2[i] > '9'){
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
                    st.insert(Node[count1].id);
                    if(st.size() != tempsize){
                        sickid.push_back(Node[count1].id);
                        sickname.push_back(Node[count1].name);
                        vectornum++;
                    }
                }
                count1++;
            }
        }
        sort(Node,Node + count1,cmp);
        for(int j=0;j<min(count1,S);j++){
            // cout << Node[j].name << " " << Node[j].id << endl;
            if(mp1.find(Node[j].id) == mp1.end()){
                mp1[Node[j].id] = i;
                cout << Node[j].name << " " << Node[j].id << endl;
            }
            else{
                if(mp1[Node[j].id] + P < i){
                    mp1[Node[j].id] = i;
                    cout << Node[j].name << " " << Node[j].id << endl;
                }
            }
        }
    }
    for(int i=0;i<vectornum;i++){
        cout << sickname[i] << " " << sickid[i] << endl;
    }
    return 0;
}