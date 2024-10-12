#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<vector<int>>& dp) {
    dp[node][0] = par;
    for(int i=1; i<=16; i++) {
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    for(auto it : adj[node]) {
        if(it==par) continue;
        dfs(it, node, adj, dp);
    }
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

    vector<vector<int>> dp(n+1, vector<int>(17, 0));
    dfs(1, 0, adj, dp);

    int q;
    cin>>q;
    while(q--) {
        int node, k;
        cin>>node>>k;
        for(int i =16; i>=0; i--) {
            if((k>>i)&1) {
                node = dp[node][i];
            }
        }
        cout<<node<<endl;
    }
}

