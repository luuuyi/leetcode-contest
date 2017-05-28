//Simple Solution
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int lens = nums.size();
        if(lens == 1)   return 1;
        vector<bool> marks(lens, false);
        int longest = 0;
        for(int i=0;i<lens;i++){
            int k = i, count = 0;
            while(!marks[k]){
                ++count; marks[k] = !marks[k];
                k = nums[k];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};