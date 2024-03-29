class DSU {
private:
    int *parent, *unionSize;
    int numSets;
public:
    DSU(int n) {
        parent = new int[numSets = n];
        unionSize = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            unionSize[i] = 1;
        }
    };
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        numSets--;
        if (unionSize[a] < unionSize[b])
            swap(a, b);
        parent[b] = a;
        unionSize[a] += unionSize[b];
    }
    bool isSameSet(int a, int b) {
        return find(a) == find(b);
    }
    int totalSets() {
        return numSets;
    }
    int setSize(int i) {
        return unionSize[find(i)];
    }
};
