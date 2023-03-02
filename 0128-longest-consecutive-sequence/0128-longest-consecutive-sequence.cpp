class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : nums) {
            if (s.find(num-1) == s.end()) { // num is the first element of a sequence
                int currentStreak = 1;
                int currentNum = num;
                while (s.find(currentNum+1) != s.end()) {
                    currentStreak++;
                    currentNum++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};