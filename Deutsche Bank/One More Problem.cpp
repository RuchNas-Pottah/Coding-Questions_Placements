// https://www.geeksforgeeks.org/smallest-subarray-with-positive-sum-for-all-indices/

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353
vector<int> onemoreproblem(int n, vector<int> &arr){
    vector<int>ans(n),prefix(n+1),nge(n);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+arr[i];
    }
    stack<int> st;
    st.push(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && prefix[st.top()]<=prefix[i]){
            st.pop();
        }
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top()-1;
        st.push(i);
    }
    for(int i=0;i<n;i++){
        if(nge[i]==-1){
            ans[i]=0;
            continue;
        }
        ans[i]=nge[i]-i+1;
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=onemoreproblem(n,arr);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
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
