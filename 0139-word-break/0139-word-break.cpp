class Solution {

    unordered_map<string, bool> present;

    bool solve(string s, vector<string>& dict){

        if(s.length() == 0)
            return true;
        
        if(present.find(s) != present.end())
            return present[s];

        int n = s.length();

        for(int i=1;i<=n;i++){
            string substring = s.substr(0,i);
            int flag = 0;
            for(string word : dict){
                if(word == substring){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1 && solve(s.substr(i, n-i), dict) == true){
                return present[s] = true;
            }
        }
        return present[s] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        return solve(s, wordDict);

    }
};