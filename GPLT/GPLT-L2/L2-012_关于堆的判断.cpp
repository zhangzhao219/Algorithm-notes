#include <bits/stdc++.h>
using namespace std;
int heap[1010];
const int INF = 100001;
void Insertheap(int x){
    int num = 1;
    while(heap[num] != INF){
        num++;
    }
    heap[num] = x;
    while(num/2 > 0 && heap[num/2] > heap[num]){
        swap(heap[num/2],heap[num]);
        num /= 2;
    }
}
int main(void){
    // freopen("../test.in","r",stdin);
    int N,M;
    scanf("%d %d",&N,&M);
    fill(heap,heap + N + 1,INF);
    int temp;
    scanf("%d",&temp);
    heap[1] = temp;
    for(int i=1;i<N;i++){
        scanf("%d",&temp);
        Insertheap(temp);
    }
    string s1,s2,s3;
    int t1,t2;
    while(M--){
        int sign = 0;
        cin >> t1 >> s1;
        if(s1 == "and"){
            cin >> t2;
            for(int i=1;i<N;i++){
                if(((heap[i] == t1 && heap[i+1] == t2) || (heap[i] == t2 && heap[i+1] == t1)) && (i/2 == (i+1)/2)){
                    sign = 1;
                    break;
                }
            }
            cin >> s2 >> s3;
        }
        else{
            cin >> s1;
            if(s1 == "a"){
                cin >> s2 >> s3 >> t2;
                for(int i=1;i<=N;i++){
                    if(heap[i] == t2){
                        if(heap[2*i] == t1 || heap[2*i + 1] == t1){
                            sign = 1;
                        }
                        break;
                    }
                }
                
            }
            else{
                cin >> s1;
                if(s1 == "root"){
                    if(heap[1] == t1){
                        sign = 1;
                    }
                }
                else{
                    cin >> s2 >> t2;
                    for(int i=1;i<=N;i++){
                        if(heap[i] == t1){
                            if(heap[2*i] == t2 || heap[2*i + 1] == t2){
                                sign = 1;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if(sign == 0){
            printf("F\n");
        }
        else{
            printf("T\n");
        }
    }
    return 0;
}