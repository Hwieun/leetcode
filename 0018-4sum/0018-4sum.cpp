class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++) {
                long t = (long)target - (nums[i] + nums[j]);

                for(int k = j + 1, l = nums.size() - 1; k < l; k++) {
                    while(k < l && nums[k] + nums[l] > t) l--;
                    if(k < l && nums[k] + nums[l] == t) 
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while(k < l && nums[k] == nums[k+1]) k++;
                }
                while(j < nums.size() - 2 && nums[j] == nums[j+1]) j++;
            }
        }        
        
        return ans;
    }
};