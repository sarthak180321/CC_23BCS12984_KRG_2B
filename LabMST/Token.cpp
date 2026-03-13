#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>token={200,150};
    int power=150;
    sort(token.begin(),token.end());
    int score=0;
    int maxScore=0;
    int i=0;
    int j=token.size()-1;
    while(i<=j){
        if(token[i]<=power){
            score++;
            maxScore=max(maxScore,score);
            power-=token[i];
            i++;
        }
        else if(token[i]>power && score!=0){
            score--;
            power+=token[j];
            j--;
        }
        else{
            break;
        }
    }
    cout<<maxScore<<endl;
}
