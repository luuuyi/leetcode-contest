class Solution {
private:
    int GCD(int a, int b){
        if(b==0)    return a;
        else    return GCD(b, a%b);
    }
public:
    string fractionAddition(string expression) {
        if(expression[0] != '-')    expression = "+" + expression;
        int lens = expression.size();
        int p = 0, p1 = 0, p2 = 0, n1 = 0, d1 = 1;
        while(p<lens){
            for(p1=p+1;p1<lens && expression[p1]!='/';p1++);
            for(p2=p1+1;p2<lens&& expression[p2]!='+' && expression[p2]!='-';p2++);
            int n2 = stoi(expression.substr(p+1, p1 - p -1)), d2 = stoi(expression.substr(p1+1, p2 - p1 -1));
            int gcd = GCD(d1, d2);
            n1 = n1*d2/gcd + (expression[p] == '-'?-1:1)*n2*d1/gcd;
            d1 *= d2/gcd;
            p = p2; 
        }
        int gcd = GCD(abs(n1), d1);
        return to_string(n1/gcd) + "/" + to_string(d1/gcd);
    }
};