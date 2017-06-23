class Solution {
private:
    // 用一个map来维护
    map<int, int> table;
    bool initNums(int a){
        int tmp = a, divisor = 2;
        while(tmp != 1){
            if(divisor >= 10)   return false;
            if(tmp%divisor == 0){
                table[divisor]++;
                tmp /= divisor;
            }
            else{
                divisor++;
            }
        }
        return true;
    }
    // 三个2结合成8，剩下的2和3组成序列，如果为基数，第一个数保留
    // 序列中剩下的数两两相乘来组成新的数放入map
    // 组合map里面的数，如果是int范围内的输出，否则输出0
    int deal(map<int, int>& table){
        int tmp = table[2] / 3, rest = table[2] % 3;
        table[8] += tmp;
        vector<int> nums(rest, 2), nums_tmp(table[3], 3);
        table.erase(2); table.erase(3); 
        nums.insert(nums.end(), nums_tmp.begin(), nums_tmp.end());
        int lens = nums.size(), i = 0;
        if(lens > 0){
            if(lens&0x01){
                i = 1; table[nums[0]] = 1;
            }
            for(;i<lens;i+=2){
                int res = nums[i]*nums[i+1];
                table[res]++;
            }
        }
        long long res = 0;
        for(auto k=table.begin();k!=table.end();k++){
            for(int i=1;i<=k->second;i++){
                res = res*10 + k->first;
            }
        }
        if(res>=INT_MIN&&res<=INT_MAX)  return (int)res;
        else    return 0;
    }
public:
    // 先将数用质数表示
    int smallestFactorization(int a) {
        if(a == 1)  return 1;
        // 判断能否用10以内的质数表示，不能的话返回false
        if(!initNums(a))    return 0;
        return deal(table);
    }
};