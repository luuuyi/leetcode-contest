class LogSystem {
private:
    unordered_map<string, int> _table;
    unordered_map<string, int> _place;
    unordered_map<string, int> init(){
        return unordered_map<string, int>({
            {"Year", 5},
            {"Month", 8},
            {"Day", 11},
            {"Hour", 14},
            {"Minute", 17},
            {"Second", 19}
        });
    }
public:
    LogSystem() {
        _place = init();
    }
    
    void put(int id, string timestamp) {
        _table[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        // 根据给定的截止条件，选择有用的字符串段来比较
        int lens = _place[gra];
        string start = s.substr(0, lens);
        string finish = e.substr(0, lens);
        vector<int> ret;
        for(auto k=_table.begin();k!=_table.end();k++){
            string tmp = k->first.substr(0, lens);
            // 时间上的对比直接可以用字符串的比较函数来做
            if(tmp.compare(start) >= 0 && tmp.compare(finish)<=0)  ret.push_back(k->second);
        }
        return ret;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */