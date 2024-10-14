// https://www.geeksforgeeks.org/minimum-steps-required-to-reach-the-end-of-a-matrix-set-2/

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

int reachtheend(int n, int m, vector<vector<int>> &matrix){
    int steps,row,col,nrow,ncol;
    vector<int> delr={-1,0,1,0},delc={0,-1,0,1};
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{0,0}});
    vector<vector<int>>vis(n,vector<int>(m));
    vis[0][0]=1;
    while(!q.empty()){
        steps=q.front().first;
        row=q.front().second.first;
        col=q.front().second.second;
        q.pop();
        if(row==n-1 && col==m-1) return steps;
        for(int i=0;i<4;i++){
            nrow=row+matrix[row][col];
            ncol=col+matrix[row][col];
            if(nrow>=0 && nrow<n && vis[nrow][col]==0){
                q.push({steps+1,{nrow,col}});
                vis[nrow][col]=1;
            }
            if(ncol>=0 && ncol<m && vis[row][ncol]==0){
                q.push({steps+1,{row,ncol}});
                vis[row][ncol]=1;
            }
        }
    }
    return -1;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<reachtheend(n,m,matrix)<<endl;
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
