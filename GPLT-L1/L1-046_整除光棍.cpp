#include <stdio.h>
int main(){
    int n, r = 1, w = 1; //r表示1,11,111类型的数据，w记录位数
    scanf("%d", &n);
    while (r < n){
        r *= 10;
        r++;
        w++;
    }
    while (1){
        printf("%d", r / n); //输出商
        r %= n;              //取余
        if (r == 0)          //取余后，若等于0，则证明能被整除，break掉
            break;
        r = r * 10 + 1; //不等于0则在余数后一位加上1
        w++;
    }
    printf(" %d", w);
    return 0;
}
