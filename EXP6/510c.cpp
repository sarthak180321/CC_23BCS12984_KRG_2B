#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (auto& s : names) cin >> s;
    
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    bool impossible = false;
    
    for (int i = 0; i < n - 1; i++) {
        string& s = names[i];
        string& t = names[i + 1];
        int len = min(s.size(), t.size());
        bool found = false;
        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                adj[s[j]-'a'].push_back(t[j]-'a');
                indegree[t[j]-'a']++;
                found = true;
                break;
            }
        }
        if (!found && s.size() > t.size()) impossible = true;
    }
    
    if (impossible) { cout << "Impossible\n"; return 0; }
    
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (indegree[i] == 0) q.push(i);
    
    string result = "";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result += (char)('a' + u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    
    if (result.size() < 26) cout << "Impossible\n";
    else cout << result << "\n";
    
    return 0;
}
