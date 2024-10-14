// https://www.thejoboverflow.com/p/p1273/

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353
int largestdividingk(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> divisors;
    int cntz = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];

        if (num == 0)
        {
            cntz++;
            continue;
        }
        for (int div = 1; div * div <= num; div++)
        {
            if (num % div == 0)
            {
                divisors[div]++;
                if (num / div != div)
                {
                    divisors[num / div]++;
                }
            }
        }
    }
    int mx = -1;
    for (auto divisor : divisors)
    {
        if (divisor.second + cntz >= k)
        {
            mx = max(mx, divisor.first);
        }
    }
    return mx;
}
void solve()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << largestdividingk(n, k, arr) << endl;
    return;
}

int main()
{
    IOS;
    ll t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
