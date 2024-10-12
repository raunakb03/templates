#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<vector<int>>& dp, vector<int>& level, int l=0) {
    dp[node][0] = par;
    for(int i=1; i<=16; i++) {
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    level[node] = l;
    for(auto it : adj[node]) {
        if(it==par) continue;
        dfs(it, node, adj, dp, level, l+1);
    }
}

int getKPar(int node, int k, vector<vector<int>>& dp) {
    for(int i=16; i>=0; i--) {
        if((k>>i)&1) {
            node = dp[node][i];
        }
    }
    return node;
}

void solve() {
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n+1, vector<int> (17, 0));
    vector<int> level(n+1, 0);
    dfs(1, 0, adj, dp, level);

    int q;
    cin>>q;
    while(q--) {
        int a, b;
        cin>>a>>b;
        if(a==b) {
            cout<<a<<endl;
            continue;
        }
        if(level[a]>level[b]) {
            swap(a, b);
        }
        int k = level[b]-level[a];
        b = getKPar(b, k, dp);
        for(int i=16; i>=0; i--) {
            if(dp[a][i]!=dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout<<dp[a][0]<<endl;
    }
}
