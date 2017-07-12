class Solution {
private:
    // 在每一个表达式之前添加符号，使得可以通过 符号+数值 的格式去解析字符串
    vector<int> solve(string equation){
        string tmp;
        if(equation.front() != '-')   tmp = "+" + equation;
        else    tmp = equation;
        string s; vector<int> ret(2, 0);
        for(int i=0;i<(int)tmp.size();i++){
            if(tmp[i]=='+'||tmp[i]=='-'){
                if(!s.empty()){
                    if(s.back() == 'x') ret[0] += (s.front()=='+'?1:-1) * (s.size()==2?1:stoi(s.substr(1, (int)s.size()-2)));
                    else    ret[1] += (s.front()=='+'?1:-1) * stoi(s.substr(1));
                    s.clear();
                }
                s.push_back(tmp[i]);
            }
            else    s.push_back(tmp[i]);
        }
        if(!s.empty()){
            if(s.back() == 'x') ret[0] += (s.front()=='+'?1:-1) * (s.size()==2?1:stoi(s.substr(1, (int)s.size()-2)));
            else    ret[1] += (s.front()=='+'?1:-1) * stoi(s.substr(1));
            s.clear();
        }
        return ret;
    }
public:
    string solveEquation(string equation) {
        // 将一个表达式分成两部分，分别计算出两部分的结果
        int pos = equation.find('=');
        vector<int> left = solve(equation.substr(0, pos));
        vector<int> right = solve(equation.substr(pos+1));
        int x = left[0] - right[0], nums = right[1] - left[1];
        // 最后统一计算
        if(x == 0 && nums == 0) return "Infinite solutions";
        else if(x == 0 && nums != 0)    return "No solution";
        else    return "x=" + to_string(nums/x);
    }
};