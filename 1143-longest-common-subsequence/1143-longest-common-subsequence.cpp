class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();

        int t[m+1][n+1];

        memset(t,-1,sizeof(t));

        int lcs = 0;

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){

                if(i==0 || j==0){
                    t[i][j] = 0;
                    continue;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }

                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }

            }
        }

        return t[m][n] > 0 ? t[m][n] : 0;

    }
};