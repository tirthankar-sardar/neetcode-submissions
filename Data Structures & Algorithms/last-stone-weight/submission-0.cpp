class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        for(auto it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){ //there should be atleast 2 element in the priority queue
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a > b){
                int c = a - b;
                pq.push(c);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
