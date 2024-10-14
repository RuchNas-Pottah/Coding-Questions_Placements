
#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

vector<long long>f;

vector<long long> precalced(int n, vector<long long> &f){
    vector<long long>s(n+1);
    f.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            s[j]+=i;
            f[j]+=s[i];
        }
        f[i]=f[i]+f[i-1];
    }
    return f;
}

long long calculatesum(int l, int r){
    return f[r]-f[l-1];
}

void solve()
{
    precalced(1e6,f);
    int q;
    cin>>q;
    vector<vector<int>>ranges(q,vector<int>(2));
    for(int i=0;i<q;i++){
        cin>>ranges[i][0]>>ranges[i][1];
        cout<<calculatesum(ranges[i][0],ranges[i][1])<<endl;
    }
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
