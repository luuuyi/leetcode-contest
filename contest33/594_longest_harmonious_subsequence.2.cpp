class Solution {
public:
    int findLHS(vector<int>& nums) {
        int lens = nums.size();
        if(lens == 0)   return 0;
        map<int, int> tab;
        for(int i=0;i<lens;i++){
            tab[nums[i]]++;
        }
        int max_val = 0;
        for(auto k=tab.begin();k!=tab.end();k++){
            if(tab.find(k->first+1)!=tab.end()){
                max_val = max(max_val, k->second + tab[k->first+1]);
            }
        }
        return max_val;
    }
};