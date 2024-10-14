
#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

int tiktok(int n, vector<int> &arr){
    int countone=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) countone++;
    }
    int mn=0;
    for(int i=0;i<countone;i++){
        if(arr[i]==0) mn++;
    }
    int cnt=0;
    for(int i=n-1;i>=n-countone;i--){
        if(arr[i]==0) cnt++;
    }
    return min(mn,cnt);
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<tiktok(n,arr)<<endl;
    return;
}

int main()
{
    IOS;
    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
