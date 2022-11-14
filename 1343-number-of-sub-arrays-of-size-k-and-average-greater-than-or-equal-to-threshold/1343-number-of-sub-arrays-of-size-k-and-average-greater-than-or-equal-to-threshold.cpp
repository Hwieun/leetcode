class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size() < k) return 0;
        
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < k; i++) sum += arr[i];
        
        for(int i = k; i < arr.size(); i++) {
            if(sum / k >= threshold) ans++;
            
            sum = sum - arr[i - k] + arr[i];
        }
        
        return sum / k >= threshold ? ans+1 : ans;
    }
};