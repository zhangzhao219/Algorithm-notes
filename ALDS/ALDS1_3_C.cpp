#include<stdio.h>
#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

list<int> v;

int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string temp;
        int num;
        cin >> temp;
        if(temp[0] == 'i'){
            scanf("%d",&num);
            v.push_front(num);
        }
        else if(temp[6] == 'F'){
            v.pop_front();
        }
        else if(temp[6] == 'L'){
            v.pop_back();
        }
        else{
            scanf("%d",&num);
            for(list<int>::iterator it = v.begin();it != v.end();it++){
                if(*it == num){
                    v.erase(it);
                    break;
                }
            }
        }
    }
    int i=0;
    for(list<int>::iterator it = v.begin();it != v.end();it++){
        if(i++){
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}