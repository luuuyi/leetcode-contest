class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int h = nums.size(), w = nums[0].size();
        if(h*w < r*c)   return nums;
        vector<vector<int>> ret(r, vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int index = i*c+j;
                ret[i][j] = nums[index/w][index%w];
            }
        }
        return ret;
    }
};