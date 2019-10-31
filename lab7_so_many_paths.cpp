/*
Author : Divyansh Shrivastava (divxvid)
*/

#include <bits/stdc++.h>
using namespace std ;

int dfs(int node, const auto &adj, auto &D, int depth, auto &dpt) {
    D[node] = 1; 
    dpt[node] = depth ;
    for(const auto &a : adj[node]) {
        if(D[a] != -1) continue ;
        D[node] += dfs(a, adj, D, depth+1, dpt) ;
    }
    return D[node] ;
}
int main() {
    
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    
    int N, Q, src, dst ;
    cin >> N >> Q ;
    
    vector<vector<int>> adj(N+1) ;
    vector<pair<int, int>> edges ;
    
    for(int i = 1 ; i < N ; i++) {
        cin >> src >> dst ;
        adj[src].push_back(dst) ;
        adj[dst].push_back(src) ;
        edges.emplace_back(src, dst) ;
    }
    
    vector<long long> forward_distance(N+1, -1) ;
    vector<int> depth(N+1, -1) ;
    dfs(1, adj, forward_distance, 1, depth) ;
    
    int e_no ;
    const long long total_nodes = forward_distance[1] ;
    
    while(Q--) {
        cin >> e_no ;
        int fst = edges[e_no-1].first ;
        int snd = edges[e_no-1].second ;
        if(depth[fst] > depth[snd]) {
            dst = fst ;   
        } else {
            dst = snd ;
        }
        cout << forward_distance[dst] * (total_nodes - forward_distance[dst]) << '\n' ; 
    }
    
    return 0 ;
}
