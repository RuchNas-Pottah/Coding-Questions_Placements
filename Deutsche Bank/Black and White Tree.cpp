#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

pair<ll,ll> dfs(int node, vector<vector<int>> &adj, vector<ll> &ans, string &s, vector<int> &vis){
    vis[node]=1;
    ll black=0ll,white=0ll;
    pair<ll,ll>tmp;
    for(auto ele:adj[node]){
        if(vis[ele]==0){
            tmp=dfs(ele,adj,ans,s,vis);
            black+=tmp.first;
            white+=tmp.second;
        }
    }
    if(s[node]-'0'==1) black++;
    else white++;
    ans[node]=black*white;
    tmp={black,white};
    return tmp;
}

vector<vector<int>> adjacencygen(vector<vector<int>> &edges, int n){
    vector<vector<int>> adj(n);
    for(auto i:edges){
        adj[i[0]-1].push_back(i[1]-1);
        adj[i[1]-1].push_back(i[0]-1);
    }
    return adj;
}

vector<ll> blackandwhitetree(int n, string &s, vector<vector<int>> &edges){
    vector<vector<int>> adj=adjacencygen(edges,n);
    vector<int>vis(n);
    vector<ll>ans(n);
    dfs(0,adj,ans,s,vis);
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>edges(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<ll>ans=blackandwhitetree(n,s,edges);
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
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
