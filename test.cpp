#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n = 2048;
    double db = 3.14;
    char str2[100] = "hello";

    char str[100];
    sprintf(str,"%d:%lf,%s",n,db,str2);
    printf("%s",str);
    return 0;
}