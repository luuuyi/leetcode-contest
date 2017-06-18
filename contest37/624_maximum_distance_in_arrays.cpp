//TLE Solution
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int lens = arrays.size();
        int ret = 0;
        for(int i=0;i<lens;i++){
            for(int j=0;j<lens;j++){
                if(i != j){
                    ret = max(ret, arrays[i].back()-arrays[j].front());
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //用一个外部变量来维护最大距离差值
        int ret = 0;
        int min_val = arrays[0].front(), max_val = arrays[0].back();
        for(int i=1;i<(int)arrays.size();i++){
            //每一次计算分别选择当前array的最大值，最小值来计算差值，并保存最大值
            ret = max(arrays[i].back()-min_val, ret);
            ret = max(max_val-arrays[i].front(), ret);
            //更新当前array之前的所有array维护出来的最大值和最小值
            min_val = min(min_val, arrays[i].front());
            max_val = max(max_val, arrays[i].back());
        }
        return ret;
    }
};