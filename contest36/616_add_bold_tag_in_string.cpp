class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int s_lens = s.size();
        vector<bool> marks(s_lens, false);
        int lens = dict.size();
        for(int i=0;i<lens;i++){
            int start = 0, pos = 0;
            while((pos = s.find(dict[i], start))!=string::npos){
                for(int j=pos;j<pos+dict[i].size();j++){
                    marks[j] = true;
                }
                start = pos + 1;
            }
        }
        string ret;
        //查找一个字符串的情况
        for(int i=0;i<s_lens;){
            if(marks[i]){
                ret += "<b>";
                while(i<s_lens){
                    if(marks[i])    ret.push_back(s[i++]);
                    else    break;
                }
                ret += "</b>";
            }
            else{
                ret.push_back(s[i++]);
            }
        }
        return ret;
    }
};