// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/0
// https://www.geeksforgeeks.org/problems/prime-factors5052/ [Prime factorization using spf]
// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353
void sieve(vector<int> &spf, int n){
    for(int i=0;i<=n;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    return;
}

int countofprimefactors(int num, vector<int> &spf){
    int copy=num;
    unordered_set<int>st;
    while(copy>1){
        st.insert(spf[copy]);
        copy/=spf[copy];
    }
    return st.size();
}

int minimumofmaximuminksizedwindow(int n, int k, vector<int> &arr){
    int mn=1e9;
    int mnindx=-1;
    deque<int>dq;
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    if(arr[dq.front()]<mn){
        mn=arr[dq.front()];
        mnindx=dq.front();
    }
    for(int i=k;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(arr[dq.front()]<mn){
            mn=arr[dq.front()];
            mnindx=i;
        }
    }
    return mnindx;
}

int valueofanexpression(int n, int k, vector<int> &arr){
    vector<int>spf(1e6+1);
    sieve(spf,1e6);
    vector<int>pfcount(n);
    for(int i=0;i<n;i++){
        pfcount[i]=countofprimefactors(arr[i],spf);
    }
    return arr[minimumofmaximuminksizedwindow(n,k,pfcount)];
}

void solve()
{
    int n,x;
    cin>>x>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<valueofanexpression(n,x,arr)<<endl;
    return;
}

int main()
{
    IOS;
    ll t = 1ll;
    while (t--)
    {
        solve();
    }
    return 0;
}
