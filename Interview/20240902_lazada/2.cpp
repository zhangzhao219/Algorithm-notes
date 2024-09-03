#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> person(n);
    vector<vector<int> >ability(n, vector<int>(n, 0));
    for(int i=0;i<n;i++){
        cin >> person[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ability[i][j];
        }
    }
    cout << *max_element(person.begin(), person.end()) << endl;
    // for(int i=0;i<n;i++){
    //     cout << person[i] << endl;
    //     for(int j=0;j<n;j++){
    //         cout << ability[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
// 64 位输出请用 printf("%lld")


// 3
// 1 1 1
// 0 1 2
// 1 0 2
// 0 -100 0

// 4

// 3
// 3 5 7
// 0 -100 -100
// -100 0 -100
// -100 -100 0

// 7