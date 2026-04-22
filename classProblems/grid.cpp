#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 3;
const int INF = (int)1e8;
int n;
vector<vector<char>> grid;
vector<vector<int>> memo;
int dp(int i, int j) {
	if(grid[i][j] == '*') return 0;
	if(i == n-1 && j == n-1) {
		return 1;
	}
	if(memo[i][j] != -1) return memo[i][j];
	int down = 0;
	int right = 0;
	if(i + 1 < n && grid[i + 1][j] != '*') down = dp(i + 1, j);
	if(j + 1 < n && grid[i][j + 1] != '*') right = dp(i, j + 1);
	return memo[i][j] = (down + right) % mod;
}
 
int main() {
	cin>>n;
	grid.resize(n, vector<char>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>grid[i][j];
		}
	}
	memo.resize(n, vector<int>(n, -1));
	cout<<dp(0, 0)<<'\n';
}
