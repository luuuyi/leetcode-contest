//有点类似于背包问题，但是不同的是约束条件和要求问题解需要的条件是一个属性
//背包问题的话，约束条件是空间，但是所需解确是价值总量最大，不同的属性造就了不同的解决方法
class Solution {
public:
    //在类定义中使用sort的cmp函数，需要将其定义为静态成员函数
    static bool cmp(vector<int>a, vector<int>b){
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {
        //首先按课程截止时间排序，升序规则
        sort(courses.begin(), courses.end(), cmp);
        multiset<int> table;
        int cur = 0;
        for(int i=0;i<(int)courses.size();i++){
            //如果当前课程加上当前时刻不大于课程截止时间，那就计算进去
            if(cur+courses[i][0] <= courses[i][1]){
                table.insert(courses[i][0]);
                cur += courses[i][0];
            }
            //如果上述条件不满足，那就考虑从之前记录的课程中，选择一个
            //所花费时间比当前时间还要长的课程，删除掉它，以保证最终选
            //择的课程数量最多
            else if(*table.rbegin() > courses[i][0]){
                cur += courses[i][0] - (*table.rbegin());
                //erase方法并不能接受reverse_iterator
                table.erase(--table.end());
                table.insert(courses[i][0]);
            }
        }
        return table.size();
    }
};