class Solution {
public:
    
    bool isPalin(string s){
        int i = 0, j = s.length()-1;
        while(i<=j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        
        string word  = "";
        
        int n = s.length();
        
        for(int i=0;i<n;i++){
            if(isdigit(s[i]))
                word += s[i];
            if(isalpha(s[i])){
                word += ::tolower(s[i]);
            }
        }
                
        if(isPalin(word))
            return true;
        
        return false;    
        
    }
};