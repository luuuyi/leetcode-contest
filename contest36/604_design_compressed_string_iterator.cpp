//MLE
class StringIterator {
private:
    string _ori;
    vector<vector<long long>> _table;

    void processString(string &s){
        string ret;
        int lens = s.size();
        for(int i=0;i<lens;){
            if(!(s[i]>='0'&&s[i]<='9')){
                int start = ++i;
                while(i<lens){
                    if(s[i]>='0'&&s[i]<='9')    ++i;
                    else    break;
                }
                int end = i;
                long long nums = stoi(s.substr(start, end-start));
                long long index = start - 1;
                _table.push_back({index, nums});
            }
        }
    }
public:
    StringIterator(string compressedString) {
        _ori = compressedString;
        processString(_ori);
    }
    
    char next() {
        for(int i=0;i<_table.size();i++){
            if(_table[i][1]>0){
                _table[i][1]--;
                return _ori[_table[i][0]];
            }
        }
        return ' ';
    }
    
    bool hasNext() {
        for(int i=0;i<_table.size();i++){
            if(_table[i][1]>0){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */