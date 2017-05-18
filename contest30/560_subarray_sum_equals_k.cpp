class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int lens = nums.size();
        if(lens==0) return 0;
        int ret = 0;
        for(int i=0;i<lens;i++){
            int tmp = 0;
            for(int j=i;j<lens;j++){
                tmp += nums[j];
                if(tmp==k)  ++ret;
            }
        }
        return ret;
    }
};

//cost spatial to solve time
//every index records the sum from 0 to index 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int lens = nums.size();
        if(lens==0) return 0;
        int ret = 0, sum = 0;
        map<int, int> mp; mp[0]++;
        for(int i=0;i<lens;i++){
            sum += nums[i];
            if(mp.find(sum-k)!=mp.end())    ret+=mp[sum-k];
            mp[sum]++;
        }
        return ret;
    }
};