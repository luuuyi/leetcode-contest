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
    void dfs(TreeNode* root, int v, int d, int cur){
        //判断边缘情况，符合的话记得返回，不符合继续dfs
        if(root == NULL)    return;
        if(cur == d){
            TreeNode* new_left = new TreeNode(v); new_left->left = root->left;
            TreeNode* new_right = new TreeNode(v); new_right->right = root->right;
            root->left = new_left; root->right = new_right;
            return;
        }
        dfs(root->left, v, d, cur+1);
        dfs(root->right, v, d, cur+1);
    }
public:
    //递归解决树的深度优先问题
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        int real = d - 1;
        //如果real为根节点，所以直接用来作为根节点，左节点为原来的树
        if(real == 0){
            TreeNode* ret = new TreeNode(v);
            ret->left = root;
            return ret;
        }
        else{
            TreeNode* ret = root;
            dfs(root, v, real, 1);
            return ret;
        }
    }
};