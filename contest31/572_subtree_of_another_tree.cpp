/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool judge(TreeNode* s, TreeNode* t){
        if(s==NULL&&t==NULL)    return true;
        if(s==NULL||t==NULL)    return false;
        if(s->val!=t->val)  return false;
        return judge(s->left,t->left)&&judge(s->right,t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL&&t==NULL)    return true;
        if(s==NULL||t==NULL)    return false;
        if(s->val==t->val){
            if(judge(s,t))  return true;
        }
        return isSubtree(s->left,t)||isSubtree(s->right,t);
    }
};