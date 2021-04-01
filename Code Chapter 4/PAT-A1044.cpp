#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long

using namespace std;
const int maxn = 1e5 + 100;
int n, m;
int a[maxn];
vector<pair<int, int>> ans;

int main(void)
{
    int mi = INF;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), a[i] += a[i - 1];
    for (int i = 0; i <= n; i++)
    {
        int pos = lower_bound(a + 1, a + n + 1, a[i] + m) - a;
        if (a[pos] - a[i] < m)
            break;
        if (a[pos] - a[i] < mi)
        {
            ans.clear();
            ans.push_back(make_pair(i + 1, pos));
            mi = a[pos] - a[i];
        }
        else if (a[pos] - a[i] == mi)
            ans.push_back(make_pair(i + 1, pos));
    }
    for (int i = 0; i < ans.size(); i++)
        printf("%d-%d\n", ans[i].first, ans[i].second);
    return 0;
}