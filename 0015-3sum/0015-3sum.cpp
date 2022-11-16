class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while(k > j && nums[j] + nums[k] + nums[i] > 0) k--;
                if(k > j && nums[j] + nums[k] + nums[i] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
                while(k > j && nums[j] == nums[j + 1]) j++;
            }
        }
        
        return ans;
    }
};