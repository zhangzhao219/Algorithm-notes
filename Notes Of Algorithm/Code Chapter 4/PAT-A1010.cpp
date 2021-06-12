#include <iostream>
using namespace std;
long long int getNum(string s, long long int radix)
{
    long long int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] >= 0 && s[i] <= '9' ? s[i] - '0' : s[i] - 'a' + 10;
        sum = sum * radix + val;
    }
    return sum;
}
int main()
{
    string s1, s2;
    int tag, maxR = 0;
    long long int radix;
    cin >> s1 >> s2 >> tag >> radix;
    long long int a = tag == 1 ? getNum(s1, radix) : getNum(s2, radix);
    s2 = tag == 1 ? s2 : s1;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] <= '9' && s2[i] >= '0')
            maxR = maxR > s2[i] - '0' ? maxR : s2[i] - '0';
        else if (s2[i] >= 'a' && s2[i] <= 'z')
            maxR = maxR > s2[i] - 'a' + 10 ? maxR : s2[i] - 'a' + 10;
    }
    long long int start = maxR + 1, end = a + 1;
    while (start <= end)
    {
        long long int ans = (start + end) / 2;
        long long int temp = getNum(s2, ans);
        if (start == end && temp != a)
        {
            break;
        }
        else if (temp == a)
        {
            cout << ans << endl;
            return 0;
        }
        else if (temp > a || temp < 0)
            end = ans;
        else
            start = ans + 1;
    }
    cout << "Impossible" << endl;
    return 0;
}