#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    vector<vector<int>>jobs={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    // each jobs takes one unit if time only 
   priority_queue<std::pair<int, int>> pq;
   vector<int>hash(4,0);
   for(int i=0; i<jobs.size(); i++){
        pq.push({jobs[i][2], jobs[i][1]});
    }
    int profit=0;
while(!pq.empty()){
    auto top=pq.top();
    pq.pop();
    int deadline=top.second;
    int jobProfit=top.first;
    for(int i=deadline; i>0; i--){
        if(i<=deadline and hash[i]!=1){
            profit+=jobProfit;
            hash[i]=1;
            break;
        }
    } 
}
