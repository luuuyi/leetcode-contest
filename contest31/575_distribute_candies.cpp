class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int lens = candies.size();
        if(lens==0) return 0;
         unordered_map<int,int> mp;
         for(int i=0;i<lens;i++){
             mp[candies[i]]++;
         }
         int types = mp.size();
         return min(types,lens/2);
    }
};