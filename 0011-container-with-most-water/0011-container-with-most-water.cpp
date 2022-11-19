class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int h = min(height[l], height[r]);
        int ans = h * (r - l);
        
        while(l < r) {
            if(height[l] < height[r]) l++;
            else r--;
            
            h = min(height[l], height[r]);
            if(ans < h * (r - l))
                ans = h * (r - l);            
        }
        
        return ans;
    }
};