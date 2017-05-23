class Solution {
private:
    int d(vector<int>& p1, vector<int>& p2){
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> dist({d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)});
        return !dist.count(0) && dist.size() == 2;
    }
};