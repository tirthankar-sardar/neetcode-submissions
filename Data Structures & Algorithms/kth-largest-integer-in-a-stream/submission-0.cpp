class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_val;
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for(auto it : nums){
            add(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k_val){
            pq.pop();
        }
        return pq.top();
    }
};