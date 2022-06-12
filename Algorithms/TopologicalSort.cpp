vector<int> answer;
vector<bool> visited;
vector<int> parent;
bool cycle = false;

void dfs(vector<vector<int>>& graph, int v) {
    visited[v] = true;
    for (int edge : graph[v]) {
        if (visited[edge] && parent[v] == edge) {
            cycle = true;
            return;
        } else if (!visited[edge]) {
            parent[edge] = v;
            dfs(graph, edge);
        }
    }
    answer.pb(v);
}

reverse(answer.begin(), answer.end());
