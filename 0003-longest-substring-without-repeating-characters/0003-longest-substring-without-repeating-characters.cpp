class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = s.length()-1;
        int i=0,j=0;
        int maxlen = 0;
        unordered_map<char, int> m;
        while(j<s.length()){
            m[s[j]]++;
            if(m.size() == j-i+1){
                maxlen = max(maxlen, j-i+1);
                j++;
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        
        return maxlen;
    }
};