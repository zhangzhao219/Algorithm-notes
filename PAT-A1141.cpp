#include <bits/stdc++.h>
using namespace std;
struct node{
    int rank;
    string name;
    double score;
    int count;
    node(){
        score = 0.0;
        count = 0;
    }
}Node[100010];
bool cmp(node a,node b){
    if(a.score != b.score){
        return a.score > b.score;
    }
    else if(a.count != b.count){
        return a.count < b.count;
    }
    return a.name < b.name;
}
int N;
string deal(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
map<string,int> mp;

int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    string s1,s2;
    int index = 0;
    int ts;
    while(N--){
        cin >> s1 >> ts >> s2;
        s2 = deal(s2);
        if(mp.find(s2) == mp.end()){
            // cout << s2 << " " << index << endl;
            mp[s2] = index;
            Node[index].name = s2;
            index++;
        }
        int index2 = mp[s2];
        Node[index2].count++;
        if(s1[0] == 'A'){
            Node[index2].score += ts;
        }
        else if(s1[0] == 'B'){
            Node[index2].score += ts / 1.5;
        }
        else{
            Node[index2].score += ts * 1.5;
        }
    }
    // for(int i=0;i<index;i++){
    //     cout << Node[i].rank << " " << Node[i].name << " " << int(Node[i].score) << " " << Node[i].count << endl;
    // }
    sort(Node,Node + index,cmp);
    Node[0].score = (int)Node[0].score;
    Node[0].rank = 1;
    for(int i=1;i<index;i++){
        Node[i].score = (int)Node[i].score;
        if(Node[i].score == Node[i-1].score){
            Node[i].rank = Node[i-1].rank;
        }
        else{
            Node[i].rank = i+1;
        }
    }
    printf("%d\n",index);
    for(int i=0;i<index;i++){
        cout << Node[i].rank << " " << Node[i].name << " " << Node[i].score << " " << Node[i].count << endl;
    }
    return 0;
}