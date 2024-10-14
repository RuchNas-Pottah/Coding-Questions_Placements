// https://www.geeksforgeeks.org/largest-prime-number-possible-from-a-subsequence-of-a-binary-string/
// https://www.naukri.com/code360/library/the-largest-prime-number-possible-from-a-subsequence-of-a-binary-string

#include <bits/stdc++.h>
#include <unordered_map>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long
#define MOD 998244353

bool checkprime(int n){
    int copy=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int binarytodec(string &s){
    int num=0;
    int sum=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        sum+=((s[i]-'0')<<num);
        num++;
    }
    return sum;
}

void recn(int indx, string &s, int n, string &now, unordered_map<string,int> &mp){
    if(indx==n){
        if(mp.find(now)==mp.end()) mp[now]=binarytodec(now);
        return;
    }
    recn(indx+1,s,n,now,mp);
    now.push_back(s[indx]);
    recn(indx+1,s,n,now,mp);
    now.pop_back();
    return;
}

int maxprime(string &s){
    int n=s.size();
    int mx=-1;
    unordered_map<string,int>mp;
    string now="";
    recn(0,s,n,now,mp);
    for(auto i:mp){
        if(checkprime(i.second)) mx=max(mx,i.second);
    }
    return mx;
}

void solve()
{
    string s;
    cin>>s;
    cout<<maxprime(s)<<endl;
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
