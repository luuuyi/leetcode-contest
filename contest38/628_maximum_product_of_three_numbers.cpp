//理解题意，最大的结果需要乘法来计算
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lens = nums.size();
        //判断最后一位是否是0，如果是零的话，那就保证了之前的数全是负数（无重复数）
        if(nums[lens-1] != 0){
            //不是0的情况下，两种可能
            int x = nums[lens-1] * nums[lens-2] * nums[lens-3];
            int y = nums[0] * nums[1] * nums[lens-1];
            return x>y?x:y;
        }
        else   return nums[lens-2] * nums[lens-3] * nums[lens-4];
    }
};