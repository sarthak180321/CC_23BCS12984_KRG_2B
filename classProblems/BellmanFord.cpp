#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,vector<pair<int,int>>> g;
int main(){
    int edge_count;
    cout<<"this is with bellman ford algorithm "<<endl;
    cout<<"enter the number of edges "<<endl;
    cin>>edge_count;
    unordered_map<int,vector<pair<int,int>>> g;
    cout<<"enter the edges value source destination and weight"<<endl;
    for(int i=0; i<edge_count; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int src;
    cout<<"enter the source node "<<endl;
    cin>>src;
    vector<int>dist(10,1e9);
    dist[src]=0;
    for(int i=1; i<=10; i++){
       for(auto it: g){
            int left=it.first;
            if(dist[left]!=1e9){
                for(auto it:g[left]){
                    int right=it.first;
                    int wt=it.second;
                    if(dist[left]+wt<dist[right]){
                        if(i==10){
                            cout<<"negative weight cycle is present "<<endl;
                            return 0;
                        }
                        dist[right]=dist[left]+wt;
                    }
                }
            }
       }
    }
    for(int i=0; i<dist.size(); i++){
        if(dist [i]!=1e9){
            cout<<"distance from source "<<src<<" to node "<<i<<" is "<<dist[i]<<endl;
        }
    }
}
