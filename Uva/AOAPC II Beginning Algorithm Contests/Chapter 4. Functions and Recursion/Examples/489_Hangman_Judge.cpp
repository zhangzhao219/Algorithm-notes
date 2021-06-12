#include <bits/stdc++.h>
using namespace std;
bool have[26];
int main(void){
    int n;
    while(1){
        scanf("%d",&n);
        if(n == -1){
            return 0;
        }
        printf("Round %d\n",n);
        string s1;
        string s2;
        cin >> s1 >> s2;
        memset(have,false,sizeof(have));
        for(int i=0;i<s1.size();i++){
            have[s1[i] - 'a'] = true;
        }
        int count1 = 0;
        int sign = 0;
        for(int i=0;i<s2.size();i++){
            if(have[s2[i] - 'a'] == true){
                have[s2[i] - 'a'] = false;
            }
            else{
                count1++;
            }
            if(count1 == 7){
                for(int i=0;i<26;i++){
                    if(have[i] == true){
                        printf("You lose.\n");
                        sign = 1;
                        break;
                    }
                }
                break;
            }
        }
        if(sign == 0){
            for(int i=0;i<26;i++){
                if(have[i] == true){
                    printf("You chickened out.\n");
                    sign = 1;
                    break;
                }
            }
            if(sign == 0){
                printf("You win.\n");
            }
        }
    }
}