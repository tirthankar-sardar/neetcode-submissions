#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mpp;
        for(int num : nums){
            if(mpp.count(num)){
                return true;
            }
            mpp.insert(num);
        }
        return false;
    }
};