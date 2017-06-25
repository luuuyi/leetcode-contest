class Excel {
private:
    vector<vector<int>> _vec(30, vector<int>(30, 0));
    int max_col; int max_row;
    map<vector<string>, string> table;
public:
    Excel(int H, char W) {
        max_col = W - 'A';
        max_row = H - 1;
    }
    
    void set(int r, char c, int v) {
        int x = r - 1;
        int y = c - 'A';
        //_vec[x][y] = v;
        //
    }
    
    int get(int r, char c) {
        int x = r - 1;
        int y = c - 'A';
        return _vec[x][y];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int x = r - 1;
        int y = c - 'A';
        int lens = strs.size();
        for(int i=0;i<lens;i++){
            string tmp = strs[i];
            if(tmp.size() == 2){
                int w = tmp[1] - '1';
                int h = tmp[0] - 'A';
                _vec[x][y] += _vec[w][h];
            }
            else{
                int w1 = tmp[1] - '1';
                int h1 = tmp[0] - 'A';
                int w2 = tmp[3] - '1';
                int h2 = tmp[2] - 'A';
                for(int i=w1;i<=w2;i++){
                    for(int j=h1;j<=h2;j++) _vec[x][y] += _vec[i][j];
                }
            }
        }
        table[strs] = string({c, r+'0'});
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */