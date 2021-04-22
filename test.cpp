#include <bits/stdc++.h>
using namespace std;

// 大整数的表示
struct bign{
    int d[1000]; // 反向存储
    int len; // 方便随时获取大整数的长度
    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

// 将整数转化为大整数
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

// 比较两个bign变量的大小
int compare(bign a,bign b){
    if(a.len > b.len){
        return 1;
    }
    else if(a.len < b.len){
        return -1;
    }
    else{
        for(int i=a.len - 1;i>=0;i--){
            if(a.d[i] > b.d[i]){
                return 1;
            }
            else if(a.d[i] < b.d[i]){
                return -1;
            }
        }
        return 0;
    }
}

// 高精度加法
bign add(bign a,bign b){
    bign c;
    int carry = 0; // 进位
    for(int i=0;i<a.len || i<b.len;i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}

// 高精度减法
bign sub(bign a,bign b){
    bign c;
    for(int i=0;i<a.len || i<b.len;i++){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len-1 >= 1 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}

// 高精度与低精度的乘法
bign multi(bign a,int b){
    bign c;
    int carry = 0;
    for(int i=0;i<a.len;i++){
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0){
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

// 高精度与低精度的除法
bign divide(bign a,int b,int &r){
    bign c;
    c.len = a.len;
    for(int i=a.len - 1;i >= 0;i--){
        r = r * 10 + a.d[i];
        if(r < b){
            c.d[i] = 0;
        }
        else{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}


int main(void){
    LL d = binaryPow(11,3,5);
    printf("%d",d);
    return 0;
}