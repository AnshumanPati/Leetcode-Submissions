class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();     
        int isPalindrome[n][n];
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==j)
                    isPalindrome[i][j] = 1;
                else if(j==i+1)
                    isPalindrome[i][j] = (s[i] == s[j])?1:0;
                else
                    isPalindrome[i][j] = 0;
                
            }
            
        }
        
        for(int g=3;g<=n;g++){
            
            for(int i=0,j=i+g-1;j<n; i++,j++){
                
                isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1])?1:0;
                
            }
            
        }

        int maxlen = 0;
        int startIndex = 0;
        int endIndex = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isPalindrome[i][j]==1 && j-i+1 > maxlen){
                    maxlen = j-i+1;
                    startIndex = i;
                    endIndex = j;
                }
            }
        }

        string ans = s.substr(startIndex,maxlen);
        return ans;
        
    }
};