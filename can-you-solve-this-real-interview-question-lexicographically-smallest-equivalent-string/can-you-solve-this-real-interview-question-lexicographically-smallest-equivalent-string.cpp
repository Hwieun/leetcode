class Solution {
    char root[26];
    void init() {
        for(char c = 'a'; c <= 'z'; c++) root[c - 'a'] = c;
    }

    char getRoot(char c) {
        if(root[c - 'a'] == c) return c;
        return root[c - 'a'] = getRoot(root[c-'a']);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        init();

        queue<pair<char, char>> q;
        for(int i = 0; i < s1.length(); i++) {
            char c1 = s1[i], c2 = s2[i];
            if(c1 == c2) continue;
            if(c1 > c2) {
                c1 = s2[i]; c2 = s1[i];
            }
            q.push({c2, c1});
        }

        while(!q.empty()) {
            auto a = q.front();
            q.pop();

            char c1 = a.second, c2 = root[a.first - 'a'];
            if(c2 != a.first) {
                if(c1 > c2) {
                    c1 = root[a.first - 'a']; c2 = a.second;
                }
                q.push({c2, c1});
            }
            root[a.first-'a'] = c1;
        }

        string ans;

        for(char c : baseStr) {
            ans += getRoot(c);
        }
        return ans;
    }
};