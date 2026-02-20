#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

unordered_map<int,int> parent; // slot -> nearest free slot behind it

int find(int x){
    if(parent.find(x) == parent.end()) return x; // x abhi free hai, map me nahi
    return parent[x] = find(parent[x]); // path compression
}

int main(){
    vector<vector<int>> jobs = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    
    priority_queue<pair<int,int>> pq;
    for(auto& job : jobs)
        pq.push({job[2], job[1]});
    
    int profit = 0;
    
    while(!pq.empty()){
        auto [jobProfit, deadline] = pq.top();
        pq.pop();
        
        int freeSlot = find(deadline);
        
        if(freeSlot > 0){
            profit += jobProfit;
            parent[freeSlot] = freeSlot - 1; // occupy karo, point karo piche wale pe
        }
    }
    
    cout << "Max Profit: " << profit;
}
