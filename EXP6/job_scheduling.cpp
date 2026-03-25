class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        queue<int> q;
        vector<int> inDegree(numCourses, 0);

        for (auto it : adj) {
            for (int nb : it.second) {
                inDegree[nb]++;
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for (auto nb : adj[node]) {
                inDegree[nb]--;
                if (inDegree[nb] == 0) {
                    q.push(nb);
                }
            }
        }

        if (ans.size() == numCourses) return ans;
        return {};
    }
};
