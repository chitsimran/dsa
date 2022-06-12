vector<int> answer;
vector<int> color;
vector<int> parent;
bool cycle = false;

void dfs(vector<vector<int>>& graph, int v) {
    color[v] = 1;
    for (int edge : graph[v]) {
        if (color[edge] == 1) {
            cycle = true;
            return;
        } else if (!color[edge]) {
            parent[edge] = v;
            dfs(graph, edge);
        }
    }
    color[v] = 2;
    answer.pb(v);
}

reverse(answer.begin(), answer.end());
