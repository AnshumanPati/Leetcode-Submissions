class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> count(26); // to keep count of each character in the current window
        int max_count = 0; // to keep track of the character with maximum count in the current window
        int left = 0; // left index of the current window
        int max_len = 0; // to keep track of the maximum length of the substring
        
        for (int right = 0; right < n; ++right) {
            max_count = max(max_count, ++count[s[right]-'A']); // update max_count and increment count of current character
            while (right - left + 1 - max_count > k) { // if we can't replace k characters in the current window, shrink the window
                --count[s[left]-'A']; // decrement count of the leftmost character
                ++left; // move left index of the window to the right
            }
            max_len = max(max_len, right - left + 1); // update max_len
        }
        
        return max_len;
    }
};