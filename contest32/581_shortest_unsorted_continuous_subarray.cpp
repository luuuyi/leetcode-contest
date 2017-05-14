class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int lens = nums.size();
        vector<int> vecs(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int start=0, end = 0;
        bool first = true;
        for(int i=0;i<lens;i++){
            if(nums[i]!=vecs[i]){
                if(first){
                    start = i; first = !first;
                }
                else    end = i;
            }
        }
        return ((end - start)==0)?0:end - start + 1;
    }
};