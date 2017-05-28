class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> table;
        int lens_1 = list1.size();
        for(int i=0;i<lens_1;i++)   table[list1[i]] = i;
        int lens_2 = list2.size();
        int min_val = 0x7fffffff;
        vector<string> ret;
        for(int i=0;i<lens_2;i++){
            if(table.find(list2[i])!=table.end()){
                table[list2[i]] += i;
                if(table[list2[i]] == min_val)  ret.push_back(list2[i]);
                else if(table[list2[i]] < min_val){
                    ret.clear(); ret.push_back(list2[i]);
                    min_val = table[list2[i]];
                }
            }
        }
        return ret;
    }
};