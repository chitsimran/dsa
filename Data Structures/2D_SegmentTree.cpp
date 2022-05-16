// 2D Segment Tree
// for get queries pass args in this format -> x1, y1, x2 and y2
// for update queries pass args as -> x, y, newVal
class SegmentTree {
private:
    int n = 0, m = 0;
    vector<vector<int>> t;
    void buildY(vector<vector<int>> a, int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        } else {
            int my = (ly + ry) / 2;
            buildY(a, vx, lx, rx, vy * 2, ly, my);
            buildY(a, vx, lx, rx, vy * 2 + 1, my + 1, ry);
            t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
        }
    }
    void buildX(vector<vector<int>> a, int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            buildX(a, vx * 2, lx, mx);
            buildX(a, vx * 2 + 1, mx + 1, rx);
        }
        buildY(a, vx, lx, rx, 1, 0, m - 1);
    }
    void build(vector<vector<int>> a) {
        buildX(a, 1, 0, n - 1);
    }
    int getY(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) 
            return 0;
        if (ly == tly && try_ == ry)
            return t[vx][vy];
        int tmy = (tly + try_) / 2;
        return getY(vx, vy * 2, tly, tmy, ly, min(ry, tmy))
             + getY(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
    }
    int getX(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
        if (lx > rx)
            return 0;
        if (lx == tlx && trx == rx)
            return getY(vx, 1, 0, m - 1, ly, ry);
        int tmx = (tlx + trx) / 2;
        return getX(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry)
             + getX(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry);
    }
    void updateY(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int val) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = val;
            else
                t[vx][vy] = t[vx * 2][vy] + t[vx * 2 + 1][vy];
        } else {
            int my = (ly + ry) / 2;
            if (y <= my)
                updateY(vx, lx, rx, vy * 2, ly, my, x, y, val);
            else
                updateY(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, val);
            t[vx][vy] = t[vx][vy * 2] + t[vx][vy * 2 + 1];
        }
    }
    void updateX(int vx, int lx, int rx, int x, int y, int val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx)
                updateX(vx * 2, lx, mx, x, y, val);
            else
                updateX(vx * 2 + 1, mx + 1, rx, x, y, val);
        }
        updateY(vx, lx, rx, 1, 0, m - 1, x, y, val);
    }
public:
    SegmentTree(int N, int M, vector<vector<int>> a) {
        n = N;
        m = M;
        t.resize(4 * n + 1, vector<int>(4 * m + 1, 0));
        build(a);
    }
    int get(int x1, int y1, int x2, int y2) {
        return getX(1, 0, n - 1, x1, x2, y1, y2);
    }
    void update(int x, int y, int val) {
        return updateX(1, 0, n - 1, x, y, val);
    }
};
