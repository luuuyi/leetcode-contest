class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //先统计每个单词出现的次数
        map<int, int> table;
        for(int i=0;i<(int)tasks.size();i++)    table[tasks[i]-'A']++;
        priority_queue<int> que;
        for(auto k=table.begin();k!=table.end();k++)    que.push(k->second);
        table.clear();
        //初始化变量
        int ret = 0, interval = n+1;
        queue<int> tmp;
        while(!que.empty()){
            //这种情况下，之后需要通过interval来计算，所以最好就把interval的减一操作放到循环里面去做
            //省得在外层interval为0break之后又要减一变成-1，影响后续操作
            while(!que.empty()&&interval){
                int val = que.top(); que.pop();
                if(val - 1 > 0) tmp.push(val-1);
                interval--;
            }
            //只有在两个队列都空掉的时候才考虑增加部分次数
            if(tmp.empty() && que.empty())  ret += n+1-interval;
            //不然需要考虑idle情况，增加所有的次数n+1
            else{
                ret += n+1;
                while(!tmp.empty()){
                    int x = tmp.front(); tmp.pop();
                    que.push(x);
                }
            }
            interval = n+1;
        }
        return ret;
    }
};