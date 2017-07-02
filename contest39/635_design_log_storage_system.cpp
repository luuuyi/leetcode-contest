#include <time.h>
class LogSystem {
private:
    map<long long, int> _table;
    map<string, pair<int, string>> _rep;
    map<string, pair<int, string>> _fck;
    long long cal(string timestamp){
        string tmp = timestamp;
        tmp[4] = '-'; tmp[7] = '-'; tmp[10] = ' ';
        tm tm_; strptime(tmp.c_str(), "%Y-%m-%d %H:%M:%S", &tm_);
        tm_.tm_isdst = -1;
        long long ret = mktime(&tm_);
        return ret;
    }
    map<string, pair<int, string>> init(){
        return map<string, pair<int, string>>({
            {"Year", {4, ":12:31:23:59:59"}},
            {"Month", {7, ":31:23:59:59"}},
            {"Day", {10, ":23:59:59"}},
            {"Hour", {13,":59:59"}},
            {"Minute", {16, ":59"}}
        });
    }
    map<string, pair<int, string>> fuck(){
        return map<string, pair<int, string>>({
            {"Year", {4, ":01:01:00:00:00"}},
            {"Month", {7, ":01:00:00:00"}},
            {"Day", {10, ":00:00:00"}},
            {"Hour", {13,":00:00"}},
            {"Minute", {16, ":00"}}
        });
    }
public:
    LogSystem() {
        _rep = init();
        _fck = fuck();
    }
    
    void put(int id, string timestamp) {
        long long res = cal(timestamp);
        _table[res] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        long long start = 0;
        long long end = 0;
        if(gra.compare("Second") == 0){  end = cal(e); start = cal(s);}
        else{
            string tmp = e.substr(0, _rep[gra].first) + _rep[gra].second;
            end = cal(tmp);
            tmp = s.substr(0, _fck[gra].first) + _fck[gra].second;
            start = cal(tmp);
        }
        auto k = _table.lower_bound(start);
        vector<int> ret;
        for(;k!=_table.end();k++){
            if(k->first > end)  break;
            else    ret.push_back(k->second);
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