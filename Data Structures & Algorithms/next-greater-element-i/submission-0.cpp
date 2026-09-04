class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0; i<n1; i++){
            int target = nums1[i];
            int nextGreater = -1;

            int j=0;
            while(j<n2 && nums2[j] != target){
                j++;
            }
            for(int k=j+1; k<n2; k++){
                if(nums2[k] > nums2[j]){
                    nextGreater = nums2[k];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};