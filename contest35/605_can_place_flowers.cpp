//一维数组的题目
//用规则遍历一遍即可
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int lens = flowerbed.size();
        int sum = 0;
        for(int i=0;i<lens;i++){
            if(flowerbed[i] == 0){
                int left_right = (i-1<0?0:flowerbed[i-1]) + (i+1>=lens?0:flowerbed[i+1]);
                if(left_right == 0){
                    flowerbed[i] = 1;
                    ++sum;
                }
            }
        }
        if(sum >= n)    return true;
        else    return false;
    }
};