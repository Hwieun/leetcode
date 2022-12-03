class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, n * m));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!mat[i][j]) {
                    if(i + 1< n ) ans[i+1][j] = min(ans[i+1][j], 1);
                    if(j + 1< m) ans[i][j+1] = min(ans[i][j+1], 1);
                    ans[i][j] = 0;
                }
                else {
                    int l = INT_MAX, r = INT_MAX;
                    if(i > 0) l = ans[i-1][j] + 1;
                    if(j > 0) r = ans[i][j-1] + 1;
                    ans[i][j] = min(ans[i][j], min(l, r));
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(!mat[i][j]) {
                    if(i > 0) ans[i-1][j] = min(ans[i-1][j], 1);
                    if(j > 0) ans[i][j-1] = min(ans[i][j-1], 1);
                }
                else {
                    int l = INT_MAX, r = INT_MAX;
                    if(i + 1< n) l = ans[i+1][j] + 1;
                    if(j + 1< m) r = ans[i][j+1] + 1;
                    ans[i][j] = min(ans[i][j], min(l, r));
                }
            }
        }
        
        return ans;
    }
};