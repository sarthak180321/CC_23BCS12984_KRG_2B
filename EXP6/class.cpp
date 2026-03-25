#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<queue>
using namespace std;
class Graph{
    int n;
    unordered_map<int,vector<int>> adj;
    void TopoSort(int src, unordered_map<int,bool>& visited, stack<int>& st){
        visited[src] = true;
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                TopoSort(nbr, visited, st);
            }
        }
        st.push(src);
    }
public:
    Graph(int n){
        this->n = n;
    }
    void GiveEdges(int u, int v){
        adj[u].push_back(v);
    }
    stack<int> call_for_all_topo(){
        stack<int> st;
        unordered_map<int,bool> visited;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                TopoSort(i, visited, st);
            }
        }
        return st;
    }
    void BFStopo(){
        vector<int>indegree(n+1,0);
        vector<int>ans;
        queue<int> q;
        for(auto it :adj){
            for(auto nbr : it.second){
                indegree[nbr]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    void prims(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<bool> visited(n,false);
            pq.push({0,0});
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                int node=it.second;
                int wt=it.first;
                if(visited[node]) continue;
                visited[node]=true;
                cout<<node<<" "<<wt<<endl;
                for(auto nbr:adj[node]){
                    if(!visited[nbr]){
                        pq.push({wt+1,nbr});
                    }
                }
            }
    }
};
int main(){
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        g.GiveEdges(u, v);
    }
    stack<int> result = g.call_for_all_topo();
    while(!result.empty()){
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
    return 0;
}
