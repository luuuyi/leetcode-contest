//题目描述
/*
Input: 5
Output: 5
Explanation: 
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 

Note: 1 <= n <= 109 
*/
//TLE Solution
class Solution {
private:
    bool isValid(int num){
        int res = num & (num << 1);
        if(res == 0)    return true;
        else    return false;
    }
public:
    int findIntegers(int num) {
        int count = 0;
        for(int i=0;i<=num;i++){
            if(isValid(i))  ++count;
        }
        return count;
    }
};

//Other Solution
class Solution {
private:
    //对于一个n为的二进制数，找到其中1开头，n-1个任意数结尾的数中不满足条件的数
    //比如说n = 3，以1开头的话，不满足条件的数为：
    /*
    **110, 111
    */
    //公式如下（x为n-1）：
    //f(x) = (1+x)*x/2 - (x - 1)
    int func(int num){
        //TODO
    }
public:
    int findIntegers(int num) {
        //TODO
    }
};