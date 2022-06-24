#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
struct Node{
    bool have_value;
    int v;
    Node* left;
    Node* right;
};
int main(void){
    while(1){
        char s[maxn];
        Node* root;
        root = new Node();
        root->have_value = false;
        root->left = root->right = NULL;
        bool failed = false;
        while(1){
            if(scanf("%s",s) != 1){
                return 0;
            }
            if(strcmp(s,"()") == 0){
                break;
            }
            int v;
            sscanf(&s[1],"%d",&v);
            
            char* t = strchr(s,',')+1;
            // cout << v << " " << t << endl;
            Node* u = root;
            for(int i=0;i<strlen(t);i++){
                if(t[i] == 'L'){
                    if(u->left == NULL){
                        u->left = new Node();
                        u->left->have_value = false;
                        u->left->left = u->left->right = NULL;
                    }
                    u = u->left;
                }
                else if(t[i] == 'R'){
                    if(u->right == NULL){
                        u->right = new Node();
                        u->right->have_value = false;
                        u->right->left = u->right->right = NULL;
                    }
                    u = u->right;
                }
            }
            if(u->have_value == true){
                failed = true;
            }
            else{
                u->have_value = true;
                u->v = v;
            }
            
        }
        vector<int> ans;
        ans.clear();
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            if(u->have_value == false){
                failed = true;
                break;
            }
            else{
                ans.push_back(u->v);
                // printf("%d ",u->v);
                if(u->left != NULL){
                    q.push(u->left);
                }
                if(u->right != NULL){
                    q.push(u->right);
                }
            }
        }
        if(failed == true){
            printf("not complete\n");
        }
        else{
            for(int i=0;i<ans.size();i++){
                printf("%d",ans[i]);
                if(i == ans.size() - 1){
                    printf("\n");
                }
                else{
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
/*
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()
*/