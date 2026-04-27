#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> ans;
    long long limit = (1LL << n) - 1;
    for (long long i = 0; i <= limit; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1LL << j)) {
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
    }
    for (int i = 0; i < ans.size(); i++) {
        vector<int> temp = ans[i];
        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j] << " ";
        }
        cout << endl;
    }

    return 0;
}