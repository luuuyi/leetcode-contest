//解题思路
//https://discuss.leetcode.com/topic/93721/python-straightforward-with-explanation
class Solution {
private:
    int MOD = 1000000007;
public:
    int kInversePairs(int n, int k) {
        //空间压缩+节省时间 的做法
        //注意long long 和 int 型的区别
        vector<vector<long long>> dp(2, vector<long long>(k+2, 1));
        dp[0][0] = 0; dp[1][0] = 0;
        long long old = 0;
        for(int i=2;i<=n;i++){
            long long cur = (old==0)?1:0;
            for(int j=0;j<k+1;j++){
                long long tmp = dp[old][j+1];
                tmp -= j>=i?dp[old][j-i+1]:0;
                dp[cur][j+1] = (dp[cur][j] + tmp) % MOD;
            }
            old = cur;
        }
        return (dp[old][k+1] - dp[old][k] + MOD) % MOD;
    }
    /*int kInversePairs(int n, int k) {
        vector<long long> old(k+2, 1);
        old[0] = 0;
        for(int i=2;i<n+1;i++){
            vector<long long> cur;
            cur.push_back(0);
            for(int j=0;j<k+1;j++){
                long long tmp = old[j+1];
                tmp -= j>=i?old[j-i+1]:0;
                cur.push_back((cur.back()+tmp)%MOD);
            }
            old = cur;
        }
        //return (old[k+1] - old[k]) % MOD;
        return (old[k+1]-old[k]+MOD)%MOD;
    }*/
};