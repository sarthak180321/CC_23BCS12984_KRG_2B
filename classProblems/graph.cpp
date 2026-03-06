#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>road;
unordered_map<int,vector<int>> g;
void dfs(int src,unordered_map<int,bool> &vis){
    vis[src]=true;
    cout<<src<<" ";
    for(auto it:g[src]){
        if(!vis[it]){
            dfs(it,vis);
        }
    }
}
int main(){
    int edge_count;
    cin>>edge_count;
    for(int i=0; i<edge_count; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int count=0;
    unordered_map<int,bool>vis;
    for(auto it:g){
        if(!vis[it.first]){
            count++;
            road.push_back(it.first);
            dfs(it.first,vis);
        }
    }
    cout<<endl<<"Number of connected components: "<<count;
    cout<<endl<<"Roads";
    cout<<endl;
    for(int i=0; i<road.size()-1; i++){
        cout<<road[i]<<" "<<road[i+1]<<endl;
    }
}