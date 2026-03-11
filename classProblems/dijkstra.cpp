#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
unordered_map<int,vector<pair<int,int>>> g;
int main(){
    int edge_count;
    cout<<"enter the number of edges "<<endl;
    cin>>edge_count;
    unordered_map<int,vector<pair<int,int>>> g;
    cout<<"enter the edges value source destination and weight"<<endl;
    for(int i=0; i<edge_count; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int src;
    cout<<"enter the source node "<<endl;
    cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    vector<int>dist(1000,1e9);
    vector<int>parent(1000,-1);
    dist[src]=0;
    parent[src]=src;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int u=it.second;
        int du=it.first;
        for(auto it:g[u]){
            int v=it.first;
            int wt=it.second;
            if(du+wt<dist[v]){
                dist[v]=du+wt;
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }
    }
    for(int i=0; i<dist.size(); i++){
        if(dist[i]!=1e9){
            cout<<"distance from source "<<src<<" to node "<<i<<" is "<<dist[i]<<endl;
        }
    }
    cout<<"parent array: ";
    for(int i=0; i<parent.size(); i++){
        if(parent[i]!=-1){
            cout<<parent[i]<<" ";
        }
    }
    cout<<endl;
}
