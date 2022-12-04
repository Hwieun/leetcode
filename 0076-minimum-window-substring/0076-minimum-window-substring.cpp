class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        string ans = s;
        bool b = false;
        unordered_map<char, int> um;
        for(char tt : t) um[tt]++;

        // prev, cur 선언
        int prev = 0, cur = 0, count = 0;
        int start = 0, len = s.length();

        // 현재 들고 있는 알파벳
        unordered_map<char, int> temp;
        while(cur < s.length()) {
            if(um[s[cur]] <= 0) cur++;
            else {
                if(temp[s[cur]] < um[s[cur]]) count++;
                temp[s[cur++]]++;
            }

            while(prev < cur && count == t.length()) {
                b = true;
                while(prev < cur && um[s[prev]] <= 0) prev++;
                if(len > cur - prev) {
                    start = prev;
                    len = cur - prev;
                }
                if(temp[s[prev]] == um[s[prev]]) count--;
                temp[s[prev++]]--;
            }
        }
        
        return b ? s.substr(start, len) : "";
    }
};