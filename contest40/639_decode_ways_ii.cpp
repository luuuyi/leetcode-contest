class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1000000007;
        vector<long long> dp((int)s.size()+1, 0);
        for(int i=1;i<=(int)s.size();i++){
            if(i == 1){
                if(!(s[i-1]>='1'&&s[i-1]<='9')) dp[i] = s[i-1]=='*'?9:0;
                else    dp[i] = 1;
            }
            else{
                if(s[i-1]=='*'){
                    if(s[i-2]>='3' || s[i-2] == '0') dp[i] = (dp[i-1]*9)%MOD;
                    else if(s[i-2]<'2'&&s[i-2]>'0') dp[i] = ((dp[i-2]*9)%MOD + (dp[i-1]*9)%MOD)%MOD;
                    else if(s[i-2]=='2')    dp[i] = ((dp[i-2]*6)%MOD + (dp[i-1]*9)%MOD)%MOD;
                }
                else if(s[i-1]=='0'){
                    if(s[i-2]>='3' || s[i-2] == '0')    dp[i] = 0;
                    else if(s[i-2]>='1'&&s[i-2]<='2')   dp[i] = dp[i-2];
                    else if(s[i-2]=='*')    dp[i] = (dp[i-2]*2)%MOD;
                }
                else if(s[i-1]>='1'&&s[i-1]<='9'){
                    if(s[i-2]=='*')
                }
            }
        }
    }
};