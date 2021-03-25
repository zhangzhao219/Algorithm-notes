#include <bits/stdc++.h>
using namespace std;
vector<int> vt;
int main(void)
{
    int N;
    scanf("%d", &N);
    int n = sqrt(N);
    int j;
    long long int sum;
    for (int len = 11; len > 0; len--)
    { //长度从11递减，因为1不算，最多只有11个数相乘
        for (int i = 2; i <= n; i++)
        { //i > sqrt(N)时，sum
            sum = 1;
            for (j = i; j < len + i; j++)
            { //共乘len次，j的个数为len个
                sum *= j;
                if (sum > N) //sum > N时，没有必要继续乘下去
                    break;
            }
            if (N % sum == 0)
            {
                printf("%d\n%d", len, i); //sum从i开始乘，一直乘到j
                for (int k = i + 1; k < j; k++)
                    printf("*%d", k);
                printf("\n");
                return 0;
            }
        }
    }
    printf("1\n%d\n", N); //当N是质数时，由于1不算在内，故只有一个因子是其本身
    return 0;
}