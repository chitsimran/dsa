vector<vector<int>> graph;
vector<bool> visited;
vector<int> low, tin;
set<int> articulationNodes;
int timer;

void dfs(int node, int parent = -1) {
    visited[node] = true;
    low[node] = tin[node] = timer++;
    int children = 0;
    for (int neighbour : graph[node]) {
        if (neighbour == parent) {
            continue;
        } else if (visited[neighbour]) {
            low[node] = min(low[node], tin[neighbour]);
        } else {
            dfs(neighbour, node);
            low[node] = min(low[node], low[neighbour]);
            children++;
            if (low[neighbour] >= tin[node] && parent != -1)
                articulationNodes.insert(node);
        }
    }
    if (parent == -1 && children > 1)
        articulationNodes.insert(node);
}
