class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count; 
        for (char c : t) {
            t_count[c]++;
        }
        int remaining = t.size(); 
        int left = 0; 
        int min_len = INT_MAX; 
        int min_start = 0; 
        
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            if (t_count.find(c) != t_count.end()) {
                if (--t_count[c] >= 0) { 
                    remaining--;
                }
            }
            while (remaining == 0) { 
                if (right - left + 1 < min_len) { 
                    min_len = right - left + 1;
                    min_start = left;
                }
                char c = s[left];
                if (t_count.find(c) != t_count.end()) {
                    if (++t_count[c] > 0) { 
                        remaining++; 
                    }
                }
                left++; 
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len); 

    }
};