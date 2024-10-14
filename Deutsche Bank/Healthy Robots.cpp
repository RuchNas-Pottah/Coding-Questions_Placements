// https://leetcode.com/problems/asteroid-collision/
// https://leetcode.com/problems/robot-collisions/

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

void healthyrobots(int n, vector<vector<int>> &arr, vector<vector<int>> &ans)
{
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] == 1)
        {
            st.push({arr[i][0], 1});
        }
        else
        {
            while (!st.empty() && st.top().first < arr[i][0])
            {
                arr[i][0] -= st.top().first;
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back({arr[i][0], 0});
            }
            else if (st.top().first == arr[i][0])
            {
                st.pop();
                arr[i][0] = 0;
            }
            else
            {
                st.top().first -= arr[i][0];
            }
        }
    }
    int sz = ans.size();
    while (!st.empty())
    {
        ans.push_back({st.top().first, st.top().second});
        st.pop();
    }
    reverse(ans.begin() + sz, ans.end());
    return;
}

void solve()
{
    int n;
    vector<vector<int>> arr(n, vector<int>(2));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<vector<int>> ans;
    healthyrobots(n, arr, ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
    return;
}

int main()
{
    IOS;
    ll t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
