class Solution {
    int ans = 1;
    vector<vector<int>> child;
    string s;
    void dfs(int i, vector<int> &count) {
        int m[2] = {0,};
        for(int c : child[i]) {
            dfs(c, count);
            if(s[i] == s[c]) continue;

            if(m[0] < count[c]) {
                m[1] = max(m[1], m[0]);
                m[0] = count[c];
            }
            else if(m[1] < count[c]) m[1] = count[c];
        }

        count[i] = m[0] + 1;
        ans = max(ans, m[0] + m[1] + 1);
    }
public:
    int longestPath(vector<int>& parent, string ss) {
        child.resize(ss.length());
        vector<int> count(ss.length());
        s = ss;
        for(int i = 1; i < parent.size(); i++)
            child[parent[i]].push_back(i);

        dfs(0, count);

        return ans;
    }
};