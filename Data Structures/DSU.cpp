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
    int findSet(int a) {
        if (parent[a] == a) return a;
        return parent[a] = findSet(parent[a]);
    }
    void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return;
        numSets--;
        if (unionSize[a] < unionSize[b])
            swap(a, b);
        parent[b] = a;
        unionSize[a] += unionSize[b];
    }
    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }
    int numDisjointSets() {
        return numSets;
    }
    int sizeOfSet(int i) {
        return unionSize[findSet(i)];
    }
};
