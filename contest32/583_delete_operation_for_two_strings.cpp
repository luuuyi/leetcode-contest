class Solution {
public:
    int minDistance(string word1, string word2) {
        int lens1 = word1.size(), lens2 = word2.size();
        vector<vector<int>> dp(lens1+1,vector<int>(lens2+1,0));
        for(int i=1;i<=lens1;i++)   dp[i][0] = i;
        for(int i=1;i<=lens2;i++)   dp[0][i] = i;
        for(int i=1;i<=lens1;i++){
            for(int j=1;j<=lens2;j++){
                if(word1[i-1]==word2[j-1])  dp[i][j] = dp[i-1][j-1];
                else    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[lens1][lens2];
    }
};