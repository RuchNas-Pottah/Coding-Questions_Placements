// https://www.geeksforgeeks.org/sum-of-bitwise-or-of-each-array-element-of-an-array-with-all-elements-of-another-array/

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

void setbitsa (int n, vector<int> &a, vector<int> &setbitsina){
    int cnt=0;
    for(int i=0;i<n;i++){
        int num=a[i];
        cnt=0;
        while(num){
            if(num&1) setbitsina[cnt]++;
            num>>=1;
            cnt++;
        }
    }
}

int debugging(int n, int m, int lim, vector<int> &a, vector<int> &b){
    vector<int>sum(m);
    vector<int>setbitsina(32);
    setbitsa(n,a,setbitsina);
    vector<int>setbitsinb(32);
    vector<long long>sums(m);
    for(int i=0;i<m;i++){
        fill(setbitsinb.begin(),setbitsinb.end(),0);
        int num=b[i];
        int cnt=0;
        while(num){
            if(num&1) setbitsinb[cnt]=1;
            num>>=1;
            cnt++;
        }
        for(int j=0;j<32;j++){
            if(setbitsinb[j]==1) sums[i]+=(1<<j)*n;
            else sums[i]+=(1<<j)*setbitsina[j];
        }
    }
    sort(sums.begin(),sums.end());
    long long tillnow=0;
    for(int i=m-1;i>=0;i--){
        tillnow+=sums[i];
        if(tillnow>=lim) return m-i;
    }
    return -1;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),brr(m);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>brr[i];
    int lim;
    cin>>lim;
    cout<<debugging(n,m,lim,arr,brr)<<"\n";
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
