#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={1,1,1,3,2,2,2};
    vector<int>bit(32,0);
    for(int i=0; i<nums.size(); i++){
        int num=nums[i];
        for(int j=0; j<32; j++){
            if(num & (1<<j)){
                bit[j]++;
            }
        }
    }
    for(int i=0; i<32; i++){
        bit[i]%=3;
    }
    int ans=0;
    for(int i=0; i<32; i++){
        if(bit[i]){
            ans|=(1<<i);
        }
    }
    cout<<ans<<endl;
}
