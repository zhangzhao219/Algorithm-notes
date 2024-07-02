#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int> > result;
    vector<int> temp;
    temp.push_back(1);
    result.push_back(temp);
    if(numRows == 1){
        return result;
    }
    for(int i=2;i<=numRows;i++){
        vector<int> t;
        t.push_back(1);
        for(int j=1;j<i-1;j++){
            t.push_back(result[i-2][j-1] + result[i-2][j]);
        }
        t.push_back(1);
        result.push_back(t);
    }
    return result;
}

int main(){
    vector<vector<int> > result = generate(5);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}