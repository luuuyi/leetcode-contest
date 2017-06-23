//TLE
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int lens = nums.size();
        if(lens < 3)    return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i=0;i<lens-2;i++){
            for(int j=i+1;j<lens-1;j++){
                for(int k=j+1;k<lens;k++){
                    ret += nums[i]+nums[j]>nums[k]?1:0;
                }
            }
        }
        return ret;
    }
};

//类似于k-sum那道题，夹逼来做
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int lens = nums.size();
        if(lens < 3)    return 0;
        sort(nums.begin(), nums.end());
        int ret = 0;
        //必须固定后面的，然后在前面夹逼
        for(int i=lens-1;i>=2;i--){
            int left = 0, right = i - 1;
            while(left < right){
                if(nums[right] + nums[left] > nums[i]){
                    ret += right - left;
                    --right;
                }
                else    ++left;
            }
        }
        return ret;
    }
};