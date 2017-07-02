class Solution {
private:
    typedef struct Node{
        int _val;
        int _row;
        int _index;
        Node(int row, int index, int val):
        _row(row),_index(index),_val(val){}
    }nd;
    struct cmp{
        bool operator()(nd a, nd b){
            return a._val > b._val;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rows = nums.size();
        // 使用一个优先队列来维护，注意优先队列小顶堆的构造方法
        priority_queue<nd, vector<nd>, cmp> pq;
        int max_val = INT_MIN;
        // 先将每一个序列的第一位放入优先队列
        for(int i=0;i<rows;i++){
            nd tmp(i, 0, nums[i][0]);
            pq.push(tmp);
            max_val = max(max_val, tmp._val);
        }
        int min_range = INT_MAX;
        int ret_start = 0, ret_end = 0;
        // 因为每一个序列都有且必须选出一个数值，所以优先队列的大小不能变
        // 每一次找到其中最小的那个值，更新一下当前的区间大小
        // 将下一个和从队列中弹出的数值一个序列的数值压入队列，循环判断
        while(pq.size() == rows){
            nd tmp = pq.top(); pq.pop();
            if(max_val - tmp._val < min_range){
                min_range = max_val - tmp._val;
                ret_start = tmp._val;
                ret_end = max_val;
            }
            if(tmp._index + 1 < (int)nums[tmp._row].size()){
                nd tmp_nd(tmp._row, tmp._index+1, nums[tmp._row][tmp._index+1]);
                pq.push(tmp_nd);
                max_val = max(max_val, tmp_nd._val);
            }
        }
        return vector<int>({ret_start, ret_end});
    }
};