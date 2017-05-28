//MLE Solution
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> nums(m, vector<int>(n, 0));
        int lens = ops.size();
        int max_val = 0, count = n*m;
        for(int i=0;i<lens;i++){
            int a = ops[i][0], b = ops[i][1];
            for(int j=0;j<a;j++){
                for(int k=0;k<b;k++){
                    ++nums[j][k];
                    if(nums[j][k] == max_val){
                        ++count;
                    }
                    else if(nums[j][k] > max_val){
                        count = 1; max_val = nums[j][k];
                    }
                }
            }
        }
        return count;
    }
};

//real solution
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int lens = ops.size();
        if(lens == 0)   return n*m;
        int min_a = 0x7fffffff, min_b = 0x7fffffff;
        for(int i=0;i<lens;i++){
            int a = ops[i][0], b = ops[i][1];
            min_a = min(min_a, a);
            min_b = min(min_b, b);
        }
        int count = min_a * min_b;
        return count;
    }
};