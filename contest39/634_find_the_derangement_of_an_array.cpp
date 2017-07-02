// 错排公式
class Solution {
public:
    int findDerangement(int n) {
        const int MOD = 1000000007;
        long long a1 = 0, a2 = 1;
        long long ret = 0;
        // 错排公式是一个类似于斐波那契数列的递归公式
        // 按公式来写就好了
        if(n == 1)  return a1;
        else if(n == 2) return a2;
        else{
            for(int i=3;i<=n;i++){
                ret = (i-1)*(a1%MOD + a2%MOD) % MOD;
                a1 = a2; a2 = ret;
            }
        }
        return int((ret+MOD)%MOD);
    }
};