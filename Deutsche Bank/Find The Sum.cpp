
#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353
int findthesum(int n, vector<int> &arr){
    vector<long long>prefix(n),suffix(n);
    for(int i=0;i<n;i++){
        if(i==0){
            prefix[i]=arr[i];
            suffix[n-i-1]=arr[n-i-1];
        }
        else{
            prefix[i]=prefix[i-1]+arr[i];
            suffix[n-i-1]=suffix[n-i]+arr[n-i-1];
        }
    }
    long long mn=prefix[n-1];
    for(int i=0;i<n;i++){
        if(i==0){
            if(i+1<n){
                mn=min(mn,suffix[i+1]);
            }
            else{
                mn=min(mn,0ll);
            }
        }
        else if(prefix[i-1]%arr[i]==0){
            if(i+1<n){
                mn=min(mn,prefix[i-1]/arr[i]+suffix[i+1]);
            }
            else{
                mn=min(mn,prefix[i-1]/arr[i]);
            }
        }
    }
    return mn;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findthesum(n,arr)<<endl;
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
