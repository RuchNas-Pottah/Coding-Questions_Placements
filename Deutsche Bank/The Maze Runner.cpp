
#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

int mntime(int n, int m, char obstacle, vector<vector<char>> &grid, vector<int> &delr, vector<int> &delc, vector<vector<int>> &vis){
    queue<pair<int,pair<int,int>>>q;
    if(grid[0][0]==obstacle) return -1;
    q.push({0,{0,0}});
    vis[0][0]=1;
    while(!q.empty()){
        int time=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        if(row==n-1 && col==m-1) return time;
        for(int i=0;i<4;i++){
            int nrow=row+delr[i];
            int ncol=col+delc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=obstacle && vis[nrow][ncol]==0){
                q.push({time+1,{nrow,ncol}});
                vis[nrow][ncol]=1;
            }
        }
    }
    return -1;
}

pair<int,int> themazerunner(int n, int m, vector<vector<char>> &grid){
    vector<int>delr={-1,0,1,0},delc={0,-1,0,1};
    vector<vector<int>>vis(n,vector<int>(m,0));
    int mn1=mntime(n,m,'*',grid,delr,delc,vis);
    fill(vis.begin(),vis.end(),vector<int>(m,0));
    int mn2=mntime(n,m,'#',grid,delr,delc,vis);
    return {mn1,mn2};
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    // door: #
    // wall: *
    // clear passage: .
    pair<int,int>ans=themazerunner(n,m,grid);
    cout<<ans.first<<"\n"<<ans.second<<"\n";
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
