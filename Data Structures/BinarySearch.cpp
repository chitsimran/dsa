int bs(vector<ll> &v, int l, int r, ll key) {
    while (l <= r && r >= 0) {
        int mid = l + (r-l)/2;
        if (v[mid] == key) return mid;
        if (v[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
