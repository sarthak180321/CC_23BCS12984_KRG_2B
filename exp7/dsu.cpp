#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findParent(int u, vector<int>& parent){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}
bool Union(int u, int v, vector<int>& parent, vector<int>& size){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if(pu == pv) return false;
    if(size[pu] < size[pv]){
        parent[pu] = pv;
        size[pv] += size[pu];
        return true;
    }
    else{
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
   vector<vector<int>>kruskal;
   for(int i=0;i<m;i++){
    vector<int>pusher(3,0);
       int u,v,w;
       cin>>u>>v>>w;
       pusher[0]=w;
       pusher[1]=u;
       pusher[2]=v;
       kruskal.push_back(pusher);
   }
   sort(kruskal.begin(),kruskal.end(),[](vector<int>& a, vector<int>& b){
       return a[0]<b[0];
   });
   vector<int> size(n,1);
   int ans=0;
    for(int i=0;i<kruskal.size();i++){
        int u=kruskal[i][1];
        int v=kruskal[i][2];
        int w=kruskal[i][0];
        if(Union(u,v,parent,size)){
            ans=ans+w;
        }
    }
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" ";
    }
}
