class Excel {
private:
    vector<vector<int>> _vec;
    int max_col; int max_row;
    vector<vector<string>> _marks;
    vector<vector<bool>> _connect;
public:
    Excel(int H, char W) {
        max_col = W - 'A';
        max_row = H - 1;
        _vec = vector<vector<int>>(max_row+1, vector<int>(max_col+1, 0));
        _marks = vector<vector<string>>(max_row+1, vector<string>(max_col+1));
        _connect = vector<vector<bool>>(max_row+1, vector<bool>(max_col+1, false));
    }
    
    void set(int r, char c, int v) {
        int x = r - 1;
        int y = c - 'A';
        int diff = v - _vec[x][y];
        _vec[x][y] = v;
        _connect[x][y] = false;
        //
        for(int i=0;i<(int)_marks[x][y].size();i+=2){
            int w = _marks[x][y][i] - 'A';
            int h = _marks[x][y][i+1] - '1';
            if(_connect[h][w])    _vec[h][w] += diff;
        }
    }
    
    int get(int r, char c) {
        int x = r - 1;
        int y = c - 'A';
        return _vec[x][y];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int x = r - 1;
        int y = c - 'A';
        _vec[x][y] = 0;
        _connect[x][y] = true;
        int lens = strs.size();
        for(int i=0;i<lens;i++){
            string tmp = strs[i];
            if(tmp.size() == 2){
                int w = tmp[1] - '1';
                int h = tmp[0] - 'A';
                _marks[w][h].push_back(c);
                _marks[w][h].push_back(r+'0');
                _vec[x][y] += _vec[w][h];
            }
            else{
                int w1 = tmp[1] - '1';
                int h1 = tmp[0] - 'A';
                int w2 = tmp[4] - '1';
                int h2 = tmp[3] - 'A';
                for(int i=w1;i<=w2;i++){
                    for(int j=h1;j<=h2;j++){
                        _marks[i][j].push_back(c);
                        _marks[i][j].push_back(r+'0');
                        _vec[x][y] += _vec[i][j];
                    }
                }
            }
        }
        return _vec[x][y];
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

 class Excel {
public:
    Excel(int H, char W) {
        // initialization. Because r starts from 1, I used H+1 instead of H.
        Exl = vector<vector<int>> (H+1, vector<int>(W-'A'+1, 0));
        fward.clear();
        bward.clear();
    }
    
    void set(int r, char c, int v) {
        int col = c-'A', key = r*26+col;
        // update its value and all the sum related
        update(r, col, v);
        // This is a reset, so break all the forward links if existing
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
    }
    // update a cell and all the sum related, using BFS
    // weights are used to improve efficiency for overlapping ranges
    void update(int r, int col, int v) {
        int prev = Exl[r][col];
        Exl[r][col] = v;
        // myq is keys for cells in next level, and update is the increment for each cell
        queue<int> myq, update;
        myq.push(r*26+col);
        update.push(v-prev);
        while (!myq.empty()) {
            int key = myq.front(), dif = update.front();
            myq.pop();
            update.pop();
            if (fward.count(key)) {
                for (auto it = fward[key].begin(); it != fward[key].end(); it++) {
                    int k = it->first;
                    myq.push(k);
                    update.push(dif*(it->second));
                    Exl[k/26][k%26] += dif*(it->second);
                }
            }
        }
    }
    
    int get(int r, char c) {
        return Exl[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        // this is another reset, so break all the forward links
        int col = c-'A', key = r*26+col, ans = 0;
        if (bward.count(key)) {
            for (int k:bward[key]) {
                fward[k].erase(key);
            }
            bward[key].clear();
        }
        // get the sum over multiple ranges
        for (string str:strs) {
            int p = str.find(':'), left, right, top, bot;
            left = str[0]-'A';
            right = str[p+1]-'A';
            if (p == -1) 
                top = stoi(str.substr(1));
            else
                top = stoi(str.substr(1, p-1));
            bot = stoi(str.substr(p+2));
            for (int i = top; i <= bot; ++i) {
                for (int j = left; j <= right; ++j) {
                    ans += Exl[i][j];
                    fward[i*26+j][key]++;
                    bward[key].insert(i*26+j);
                }
            }
        }
        // update this cell and all the sum related
        update(r, col, ans);
        return ans;
    }
private:
    // The key of a cell is defined as 26*row+col, which is int;
    // fward links a cell to all the cells which use it for sum, and it may be used for 
    // multiple times due to overlap ranges, so another map is used for its weight
    // bward links a cell to all the cells that contribute to its sum. When reset its value,
    // or reassign a new sum range to it, we need disconnect the forward link of those cells to it. 
    unordered_map<int, unordered_map<int, int>> fward;
    unordered_map<int, unordered_set<int>> bward;
    vector<vector<int>> Exl;
};