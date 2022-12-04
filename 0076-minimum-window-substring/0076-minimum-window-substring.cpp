class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        unordered_map<char, int> um;
        for(char tt : t) um[tt]++;

        // l: window 의 왼쪽 인덱스, r : window의 오른쪽 인덱스, cnt: window안에 일치하는 char 개수
        // cnt == t.length() => 현재 window 내에 t의 char 가 전부 속해있음을 의미
        int l = 0, r = 0, cnt = 0;
        int astart = 0, alen = s.length();
        unordered_map<char, int> window;
        while(r < s.length()) {
            // s[r]: t에 없는 char 인 경우
            if(um[s[r]] == 0) {
                r++;
                continue;
            }
            // s[r]: t에 있는 char 인 경우
            else {
                if(window[s[r]] < um[s[r]]) cnt++;
                window[s[r++]]++;
            }

            // substring이 조건에 맞을 때. l을 다음으로 넘김
            while(cnt == t.length()) {
                while(l < r && um[s[l]] == 0) l++;
                if(alen > r - l) {
                    astart = l;
                    alen = r - l;
                }
                if(window[s[l]] == um[s[l]]) cnt--;
                window[s[l++]]--;
            }
        }

        return l == 0 ? "" : s.substr(astart, alen);
    }
};