class Solution {
public:
    bool judgeSquareSum(int c) {
        // 枚举出0到c的平方根中的数值即可
        for(int i=0;i<=sqrt(c);i++){
            int a = sqrt(c - i*i);
            if(i*i + a*a == c)  return true;
        }
        return false;
    }
};