/**
 * Detect Cycle in Directed Graph
 */
vector<int> color;
vector<int> parent;

bool dfs(vector<vector<int>>& graph, int v) {
    color[v] = 1;
    bool cycle = false;
    for (int edge : graph[v]) {
        if (color[edge] == 1) {
            return true;
        } else if (!color[edge]) {
            parent[edge] = v;
            cycle |= dfs(graph, edge);
        }
    }
    color[v] = 2;
    return cycle;
}


/**
 * Cycle in Un-Directed Graph
 */
vector<int> parent;
vector<bool> visited;

void dfs(vector<vector<int>>& graph, int v) {
    visited[v] = true;
    for (int edge : graph[v]) {
        if (visited[edge] && parent[v] != edge) {
            cycleStart = v;
            cycleEnd = edge;
            return;
        } else if (!visited[edge]) {
            parent[edge] = v;
            dfs(graph, edge);
        }
    }
}
