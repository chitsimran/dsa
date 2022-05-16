// Supports range min queries
// To support other range queries, modify accordingly
// for array queries pass 0 based index to l and r
class SegmentTree {
private:
    int n, *t;
    void build(int a[], int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
        } else {
            int mid = l + (r - l) / 2;
            build(a, v * 2, l, mid);
            build(a, (v * 2) + 1, mid + 1, r);
            t[v] = min(t[v * 2], t[(v * 2) + 1]); 
        }
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INT_MAX;
        if (l == tl && r == tr)
            return t[v];
        int mid = tl + (tr - tl) / 2;
        return min(get(2 * v, tl, mid, l, min(r, mid)), get(2 * v + 1, mid + 1, tr, max(l, mid + 1), r));
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr)
            t[v] = val;
        else {
            int mid = tl + (tr - tl) / 2;
            if (pos <= mid)
                update(2 * v, tl, mid, pos, val);
            else
                update(2 * v + 1, mid + 1, tr, pos, val);
            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }
public:
    SegmentTree(int N, int a[]) {
        n = N;
        t = new int[(4 * n) + 1];
        for (int i = 0; i < (4 * n) + 1; i++)
            t[i] = INT_MAX;
        build(a, 1, 0, n - 1);
    }
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    void update(int pos, int val) {
        return update(1, 0, n - 1, pos, val);
    }
};
