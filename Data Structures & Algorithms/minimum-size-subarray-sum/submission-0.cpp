class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int window = 0;
        int ans = INT_MAX;
        for(int right=0; right<n; right++){
            window += nums[right];
            while(window >= target){
                ans = min(ans, right-left+1);
                window -= nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};