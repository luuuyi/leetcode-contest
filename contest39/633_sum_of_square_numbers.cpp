// TLE Solution
// /2
class Solution {
public:
    bool judgeSquareSum(int c) {
        //if(c <= 1)  return false;
        for(int i=0;i*i<=c/2;i++){
            int a = sqrt(c - i*i);
            if(i*i + a*a == c)  return true;
        }
        return false;
    }
};