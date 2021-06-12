#include <bits/stdc++.h>
using namespace std;
vector<int> vt;
vector<int> vt2;
int main(void){
    int total;
    int index = 0;
    while(1){
        index++;
        cin >> total;
        if(total == 0){
            return 0;
        }
        cout << "Game " << index << ":" << endl;
        vt.clear();
        int t;
        for(int i=0;i<total;i++){
            cin >> t;
            vt.push_back(t);
        }
        while(1){
            vt2.clear();
            int sign = 0;
            for(int i=0;i<total;i++){
                cin >> t;
                if(t != 0){
                    sign = 1;
                }
                vt2.push_back(t);
            }
            if(sign == 0){
                break;
            }
            int a = 0;
            int b = 0;
            for(int i=0;i<vt.size();i++){
                if(vt[i] == vt2[i]){
                    a++;
                }
            }
            for(int d=1;d<=9;d++){
                int c1 = 0;
                int c2 = 0;
                for(int i=0;i<vt.size();i++){
                    if(vt[i] == d){
                        c1++;
                    }
                    if(vt2[i] == d){
                        c2++;
                    }
                }
                b += min(c1,c2);
            }
            
            cout << "    (" << a << "," << b-a << ")" << endl;
        }
    }
}

/*
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
*/