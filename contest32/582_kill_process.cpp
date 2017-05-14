class Solution {
private:
    void dfs(map<int,vector<int>>& mp, int kill, set<int>& ret){
        ret.insert(kill);
        if(mp.find(kill)==mp.end()) return;
        for(auto k=mp[kill].begin();k!=mp[kill].end();k++){
            int next_kill = *k;
            dfs(mp,next_kill,ret);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int lens1 = pid.size(), lens2 = ppid.size();
        if(lens1!=lens2||lens1==0||lens2==0)    return vector<int>();
        map<int,vector<int>> mp;
        for(int i=0;i<lens2;i++){
            mp[ppid[i]].push_back(pid[i]);
        }
        set<int> ret;
        dfs(mp,kill,ret);
        vector<int> result;
        for(auto k=ret.begin();k!=ret.end();k++)    result.push_back(*k);
        return result;
    }
};