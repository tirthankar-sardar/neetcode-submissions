class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();

        arr = nums;
        seg.resize(4 * n);

        build(1, 0, n - 1);
    }
    void build(int node, int start, int end) {

        if (start == end) {
            seg[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    void updateTree(int node, int start, int end, int index, int val) {

        if (start == end) {
            seg[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            updateTree(2 * node, start, mid, index, val);
        } else {
            updateTree(2 * node + 1, mid + 1, end, index, val);
        }

        seg[node] = seg[2 * node] + seg[2 * node + 1];
    }
    void update(int index, int val) {
        arr[index] = val;

        updateTree(1, 0, n - 1, index, val);
    }
    int query(int node, int start, int end, int left, int right) {

        if (right < start || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return seg[node];
        }

        int mid = (start + end) / 2;

        int leftSum = query(2 * node, start, mid, left, right);
        int rightSum = query(2 * node + 1, mid + 1, end, left, right);

        return leftSum + rightSum;
    }
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */