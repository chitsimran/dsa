class Dijkstra {
private:
    int n, *d;
    vector<bool> visited;
public:
    Dijkstra(int N, vector<vector<pair<int, int>>> graph) {
        n = N;
        d = new int[n];
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            d[i] = INT_MAX;
        }
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            int vertex = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (vertex == -1 || d[j] < d[vertex]))
                    vertex = j;
            }

            if (vertex == -1 || d[vertex] == INT_MAX)
                break;

            visited[vertex] = true;
            for (pair<int, int> edge : graph[vertex]) {
                int to = edge.first;
                int wt = edge.second;

                if (d[vertex] + wt < d[to]) {
                    d[to] = d[vertex] + wt;
                }
            }
        }
    }
    int get(int ind) {
        return d[ind];
    }
};
