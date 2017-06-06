/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //关于树的题目，好久没练习了
class Solution {
private:
    string output;
    string preorderRecursive(TreeNode* t){
        if(t == NULL)   return "()";
        string ret = "(";
        ret += to_string(t->val);
        //使用逻辑判断哪个时候该接受子树返回的值
        string left = preorderRecursive(t->left);
        string right = preorderRecursive(t->right);
        int left_val = left.compare("()"), right_val = right.compare("()");
        if(right_val != 0) ret += left + right;
        else if(left_val != 0 && right_val == 0)   ret += left;
        ret += ")";
        return ret;
    }
public:
    string tree2str(TreeNode* t) {
        output.clear();
        if(t == NULL)   return output;
        //为了防止节点有负数，所以需要直接转为字符串
        output += to_string(t->val);
        string left = preorderRecursive(t->left);
        string right = preorderRecursive(t->right);
        int left_val = left.compare("()"), right_val = right.compare("()");
        if(right_val != 0) output += left + right;
        else if(left_val != 0 && right_val == 0)   output += left;
        return output;
    }
};