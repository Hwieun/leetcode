class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = nums[0], n = nums.size();

        vector<int> right(n);
        right[n-1] = nums[n-1];
        for(int i = n-2, sum = nums[n-1]; i >=0; i--) {
            sum += nums[i];
            right[i] = max(right[i+1], sum);
        }
        
        int max_sum = ans, cur = 0;
        for(int i = 0, sum = 0; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            sum += nums[i];
            max_sum = max(max_sum, cur);
            if(i +1 < n)
            ans = max(ans, sum + right[i+1]);
        }

        return max(ans, max_sum);
    }
};