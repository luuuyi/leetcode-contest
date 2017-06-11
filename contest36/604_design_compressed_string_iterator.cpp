//MLE
class StringIterator {
private:
    string _ori;
    string _process;
    int _index, _lens;

    string processString(string &s){
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
                ret.append(string(stoi(s.substr(start, end-start)), s[start-1]));
            }
        }
        return ret;
    }
public:
    StringIterator(string compressedString) {
        _ori = compressedString;
        _process = processString(_ori);
        _lens = _process.size();
        _index = 0;
    }
    
    char next() {
        if(_index < _lens)  return _process[_index++];
        else    return ' ';
    }
    
    bool hasNext() {
        if(_index < _lens)  return true;
        else    return false;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */