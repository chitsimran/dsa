//Stores 0 to n-1 elements if initialized bit(n);
//To store elements upto n(inclusive) initialize bit(n+1);
class BIT {
private:
    int *bit, n;
public:
    BIT(int N) {
        n = N;
        bit = new int[n+1];
        for (int i = 0; i <= n; i++)
            bit[i] = 0;
    };
    void add(int ind, int val) {
        ind += 1;
        while (ind <= n) {
            bit[ind] += val;
            ind = ind + (ind & -ind);
        }
    }
    void add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    int get(int ind) {
        ind += 1;
        int res = 0;
        while (ind > 0) {
            res += bit[ind];
            ind = ind - (ind & -ind);
        }
        return res;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};
