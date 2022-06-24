#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
char s[maxn];
int last,cur,nexts[maxn];
int main(void){
    while(scanf("%s",s) == 1){
        int s_size = strlen(s);
        nexts[0] = 0;
        cur = last = 0;
        for(int i=1;i<=s_size;i++){
            char c = s[i-1];
            if(c == '['){
                cur = 0;
            }
            else if(c == ']'){
                cur = last;
            }
            else{
                nexts[i] = nexts[cur];
                nexts[cur] = i;
                if(cur == last){
                    last = i;
                }
                cur = i;
            }
        }
        for(int i=nexts[0];i != 0;i = nexts[i]){
            printf("%c",s[i-1]);
        }
        printf("\n");
    }
    return 0;
}
/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
*/