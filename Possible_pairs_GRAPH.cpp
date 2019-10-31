/*
Author : Divyansh Shrivastava (divxvid)
Description : A graph based approach to solve the question.
*/

#include <bits/stdc++.h>
using namespace std ;

int m, n ;
void dfs(auto &g, vector<bool> &visited, int idx, int &boys, int &girls)
{
    if(idx <= m) ++boys ;
    else ++girls ;
    for(const int &adj : g[idx])
    {
        if(visited[adj]) continue ;
        visited[adj] = true ;
        dfs(g, visited, adj, boys, girls);
    }
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    //int m, n ;
    cin >> m >> n ;
    
    vector<vector<int>> graph(n+m+5);
    int a, b, c;
    cin >> c ;
    for(int i = 0 ; i < c ; ++i)
    {
        cin >> a >> b ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    cin >> c ;
    for(int i = 0 ; i < c ; ++i)
    {
        cin >> a >> b ;
        a += m ;
        b += m ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    cin >> c ;
    for(int i = 0 ; i < c ; ++i)
    {
        cin >> a >> b ;
        b += m ;
        graph[a].push_back(b) ;
        graph[b].push_back(a) ;
    }
    
    vector<bool> visited(m+n+5, false) ;
    long long ans = 0 ;
    for(int i = 1 ; i <= m ; ++i)
    {
        if(visited[i]) continue ;
        visited[i] = true ;
        int n_boys = 0, n_girls = 0;
        dfs(graph, visited, i, n_boys, n_girls);
        ans += (long long)n_boys * (n - n_girls) ;
    }
    cout << ans << endl ;
    return 0 ;
}
