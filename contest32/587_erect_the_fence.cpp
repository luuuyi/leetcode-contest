//solution page:
//https://discuss.leetcode.com/topic/89340/quickhull-c-solution-29ms
class Solution {
public:
    static bool mycmp(Point &a, Point &b) {
        return a.x < b.x;
    }
    
    int testSide(Point &a, Point &b, Point &c) {
        // cross product of (AB and AC vectors)
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }
    
    double distPointLine(Point &A, Point &B, Point &C) {
        // dist(line: ax+by+c=0, and point(x0, y0)): (a*x0 + b*y0 + c)/sqrt(a^2+b^2)
        // line: (y2-y1)*x - (x2-x1)*y + x2*y1 - y2*x1 = 0
        int a = B.y - A.y, b = B.x - A.x;
        return abs((a*C.x - b*C.y + B.x*A.y - B.y*A.x)/sqrt(a*a + b*b));
    }
    
    void FindHull(vector<Point> &points, Point &A, Point &B) {
        if (points.empty())
            return;
        
        int idx = 0;
        double dist = distPointLine(A, B, points[0]);
        for (int i=1; i<points.size(); i++) {
            if (distPointLine(A, B, points[i]) > dist) {
                dist = distPointLine(A, B, points[i]);
                idx = i;
            }
        }
        ret.push_back(points[idx]);
        
        vector<Point> R, T;
        for (int i=0; i<points.size(); i++) {
            if (i != idx) {
                int tmp = testSide(A, points[idx], points[i]);
                if (tmp >= 0)
                    R.push_back(points[i]);
                else {
                    tmp = testSide(points[idx], B, points[i]);
                    if (tmp >= 0)
                        T.push_back(points[i]);
                }
            }
        }
        FindHull(R, A, points[idx]);
        FindHull(T, points[idx], B);
        
        return;
    }
    
    vector<Point> ret;
    
    vector<Point> outerTrees(vector<Point>& points) {
        // find the convex hull; use QuickHull algorithm
        if (points.size() <= 1)
            return points;
        
        // find the left most and right most two points
        sort(points.begin(), points.end(), mycmp);
        ret.push_back(points[0]);
        ret.push_back(points.back());
        
        // test whether a point on the left side right side or on the line
        vector<Point> Left, Right, Online;
        for (int i=1; i<points.size()-1; i++) {
            int tmp = testSide(points[0], points.back(), points[i]);
            if (tmp < 0)
                Right.push_back(points[i]);
            else if (tmp > 0)
                Left.push_back(points[i]);
            else
                Online.push_back(points[i]);
        }
        // if Upper or Down is empty, Online should be pushed into ret
        if (Left.empty() || Right.empty())
            for (int i=0; i<Online.size(); i++)
                ret.push_back(Online[i]);

        FindHull(Left, points[0], points.back());
        FindHull(Right, points.back(), points[0]);
        
        return ret;
    }
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    vector<Point> ret;

    double findDist(Point& A, Point& B, Point& C){
        //(y2 - y1)*x + (x1 - x2)*y + x2*y1 - x1*y2 = 0
        return abs((B.y - A.y)*C.x + (A.x - B.x)*C.y + B.x*A.y - A.x*B.y) / sqrt((B.y - A.y)*(B.y - A.y) + (A.x - B.x)*(A.x - B.x));
    }

    int findDirection(Point& A, Point& B, Point& C){
        //AB and AC
        return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
    }

    void findHull(vector<Point>& set, Point &A, Point &B){
        int lens = set.size();
        if(lens==0) return;

        int idx = 0;
        double max_dist = findDist(A, B, set[0]);
        for(int i=1;i<lens;i++){
            double dist = findDist(A, B, set[i]);
            if(dist>max_dist){
                max_dist = dist;
                idx = i;
            }
        }
        Point C = set[idx];
        ret.push_back(C);

        vector<Point> up, down;
        for(int i=0;i<lens;i++){
            if(i!=idx){
                int tmp = findDirection(A,C,set[i]);
                /*if(tmp>0)   up.push_back(set[i]);
                else if(tmp < 0){
                    int tmp_x = findDirection(C,B,set[i]);
                    if(tmp_x>0) down.push_back(set[i]);
                }*/
                if(tmp>=0)   up.push_back(set[i]);
                else{
                    int tmp_x = findDirection(C,B,set[i]);
                    if(tmp_x>=0) down.push_back(set[i]);
                }
            }
        }

        findHull(up,A,C);
        findHull(down,C,B);
    }
public:
    static bool cmp(Point a, Point b){
        if(a.x==b.x)    return a.y < b.y;
        return a.x < b.x;
    }

    vector<Point> outerTrees(vector<Point>& points) {
        int lens = points.size();
        if(lens<=1) return points;
        sort(points.begin(), points.end(), cmp);

        Point A = points[0], B = points.back();
        ret.push_back(A); ret.push_back(B);
        vector<Point> up, down, online;
        for(int i=1;i<lens-1;i++){
            int tmp = findDirection(A,B,points[i]);
            if(tmp==0)  online.push_back(points[i]);
            else if(tmp > 0)    up.push_back(points[i]);
            else    down.push_back(points[i]);
        }
        if(up.empty()||down.empty()){
            ret.insert(ret.end(),online.begin(),online.end());
        }
        findHull(up, A, B);
        findHull(down, B, A);
        return ret;
    }
};