#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    unordered_map<int,vector<pair<int,int>>> g;
    
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    vector<long long> dist(n + 1, 1e18);
    vector<int> parent(n + 1, -1);
    
    dist[1] = 0;
    parent[1] = 1;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();
        
        if(du > dist[u]) continue;
        
        for(auto [v, wt] : g[u]){
            if(du + wt < dist[v]){
                dist[v] = du + wt;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
    
    if(dist[n] == 1e18){
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> path;
    int cur = n;
    while(cur != 1){
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(1);
    
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}
