class Solution {
    vector<vector<int>> cst;
    int n;
    vector<vector<int>> memo;
    int dp(int curr, int mask) {
        if(mask == (1 << n) - 1) {
            return cst[curr][0];
        }
        if(memo[curr][mask] != -1) return memo[curr][mask];
        int res = INT_MAX;
        for(int node = 0; node < n; node++) {
            if(mask&(1 << node)) continue;
            res = min(res,
                cst[curr][node] + dp(node, mask | (1 << node)));
        }
        return memo[curr][mask] = res;
    }
  public:
    int tsp(vector<vector<int>>& cost) {
        cst = cost;
        n = cst.size();
        memo.resize(n, vector<int>(1 << n, -1));
        return dp(0, 1);
    }
};
