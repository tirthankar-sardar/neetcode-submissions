class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int total = 0;
        for(int num : nums){
            if(total < 0){
                total = 0;
            }
            total += num;
            ans = max(ans, total);
        }
        return ans;
    }
};
