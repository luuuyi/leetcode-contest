class Solution {
private:
    map<char, int> getMap(string s){
        int lens = s.size();
        map<char, int> mp;
        for(int i=0;i<lens;i++){
            mp[s[i]]++;
        }
        return mp;
    }

    vector<string> findStrings(string& s2, map<char, int>& mp){
        int lens = s2.size();
        vector<string> ret;
        int start = 0;
        for(int i=0;i<lens;i++){
            if(mp.find(s2[i])==mp.end())
        }
    }
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp = getMap(s1);
        int lens1 = s1.size(), lens2 = s2.size();
        if(lens2<lens1) return false;
        for(int i=0;i<=lens2-lens1;i++){
            map<char, int> mp_tmp = mp;
            bool is_ok = true;
            for(int j=i;j<i+lens1;j++){
                mp_tmp[s2[j]]--;
                if(mp_tmp[s2[j]]<0){
                    is_ok = false;break;
                }
            }
            if(is_ok)   return true;
        }
        return false;
    }
};

//find chars in an array, depend on left and right
class Solution {
private:
public:
    bool checkInclusion(string s1, string s2) {
        int lens1 = s1.size(), lens2 = s2.size();
        if(lens2<lens1) return false;
        vector<int> chars(26,0);
        for(int i=0;i<lens1;i++){
            chars[s1[i] - 'a']++;
        }
        int tmp = lens1;
        for(int left=0, right=0; right<lens2;right++){
            if(chars[s2[right] - 'a']-- > 0)  --tmp;
            while(tmp==0){
                if(right - left + 1 == lens1)   return true;
                if(++chars[s2[left++] - 'a'] > 0) tmp++;
            }
        }
        return false;
    }
};